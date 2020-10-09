#include "Header.h"
#include <string>

bool estPleine(const t_file& f) {
	return (f.fin + 1) % TAILLE_FILE == f.debut;
}

bool estVide(const t_file& f) {
	return f.debut == f.fin;
}

int retirer(t_file& f) {
	int piece = f.liste[f.debut].num;
	f.debut = (f.debut + 1) % TAILLE_FILE;
	return piece;
}

int retirer(t_machine& m) {
	m.etat = VIDE;
	return m.contenu.num;
}

int retirer(t_entree& e) {
	e.etat = VIDE;
	return e.contenu.num;
}

void poser(t_file& f, const t_piece& p) {
	f.liste[f.fin] = p;
	f.fin = (f.fin + 1) % TAILLE_FILE;
}

void poser(t_machine& m, const t_piece& p) {
	m.contenu = p;
	m.etat = OCCUPEE;
}


void simuler(int duree, int DA, int DT, t_systeme& systeme)
{
	/* INITIALISATION */
	const int INF = duree + 10;
	t_entree& e = systeme.e;
	t_sortie& s = systeme.s;
	t_machine& m = systeme.m;
	t_file& f = systeme.f;
	e.dateProchainEvenement = 0;
	m.dateProchainEvenement = INF;

	for (int i = 0; i <= NBPIECES; i++) {
		t_piece& p = systeme.pieces[i];
		p.num = i;
		p.dateEntreeFile = p.dateSortieFile =
			p.dateEntreeMachine = p.dateSortieMachine =
			p.dateEntreeSys = p.dateSortieSys = 0;
	}

	/* SIMULATION */
	int dateSimulation = 0;
	int imin = 1;
	int iPiece = 1;
	e.contenu = systeme.pieces[iPiece];
	while (dateSimulation < duree) {
		System::Windows::Forms::Application::DoEvents();
		// chercher entité avec DPE min
		if (e.dateProchainEvenement < m.dateProchainEvenement) {
			imin = 1;
			dateSimulation = e.dateProchainEvenement;
		}
		else {
			imin = 2;
			dateSimulation = m.dateProchainEvenement;
		}

		// si DPE min dans l'entrée
		if (imin == 1) {
			systeme.pieces[iPiece].dateEntreeSys = dateSimulation;
			// Tests sur la file
			if (estPleine(f)) {
				// entrée bloquée
				e.etat = BLOQUEE;
				e.nbPiecesPerdues++;
				e.dateProchainEvenement = INF;
			}
			else if (m.etat == VIDE) {
				// la pièce va directement sur la machine
				int numPiece = retirer(e);
				t_piece& p = systeme.pieces[numPiece];
				e.dateProchainEvenement = dateSimulation + DA;
				poser(m, p);
				p.dateEntreeMachine = dateSimulation;
				m.dateProchainEvenement = dateSimulation + DT;
			}
			else {
				// la pièce passe en file d'attente
				int numPiece = retirer(e);
				t_piece& p = systeme.pieces[numPiece];
				e.etat = VIDE;
				e.dateProchainEvenement = dateSimulation + DA;
				poser(f, p);
				p.dateEntreeFile = dateSimulation;
			}

			// Ajout de nouvelle pièce dans l'entrée
			if (iPiece < NBPIECES) {
				iPiece++;
				e.contenu = systeme.pieces[iPiece];
			}
			else {
				e.dateProchainEvenement = INF;
			}
		}

		// si DPE min dans la machine
		if (imin == 2) {
			if (m.etat == OCCUPEE) {
				int numPiece = retirer(m);
				t_piece& p = systeme.pieces[numPiece];
				p.dateSortieMachine = dateSimulation;
				p.dateSortieSys = dateSimulation;
				s.nbPieceSortie++;
				m.etat = VIDE;
			}
			if (estVide(f)) {
				m.dateProchainEvenement = INF;
			}
			else {
				int numPiece = retirer(f);
				t_piece& p = systeme.pieces[numPiece];
				p.dateSortieFile = dateSimulation;
				p.dateEntreeMachine = dateSimulation;
				if (e.etat == BLOQUEE) {
					e.dateProchainEvenement = dateSimulation;
				}
				poser(m, p);
				m.etat = OCCUPEE;
				m.dateProchainEvenement = dateSimulation + DT;
			}
		}
	}
	/* CALCUL DES TEMPS MOYENS */
	float& tpsMoyFile = s.tempsMoyenFile,
		& tpsTotMachine = s.tempsMoyenMachine,
		& tpsTotSys = s.tempsMoyenSys;
	for (int i = 1; i <= NBPIECES; i++) {
		System::Windows::Forms::Application::DoEvents();
		t_piece p = systeme.pieces[i];
		// si la pièce n'a pas été perdue
		if (p.dateSortieSys != 0) {
			tpsMoyFile += (p.dateSortieFile - p.dateEntreeFile);
			tpsTotMachine += (p.dateSortieMachine - p.dateEntreeMachine);
			tpsTotSys += (p.dateSortieSys - p.dateEntreeSys);
		}
	}
	tpsMoyFile /= s.nbPieceSortie;
	tpsTotMachine /= s.nbPieceSortie;
	tpsTotSys /= s.nbPieceSortie;
}
