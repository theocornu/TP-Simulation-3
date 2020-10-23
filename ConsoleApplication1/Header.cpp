#include "Header.h"
#include <string>

bool estPleine(const t_file& f) {
	return (f.fin + 1) % CAPACITE_FILE_FINIE == f.debut;
}

bool estVide(const t_file& f) {
	return f.debut == f.fin;
}

t_piece retirer(t_file& f) {
	t_piece piece = f.liste[f.debut];
	f.debut = (f.debut + 1) % CAPACITE_FILE_FINIE;
	f.nbPieces--;
	return piece;
}

t_piece retirer(t_machine& m) {
	m.etat = VIDE;
	return m.contenu;
}

t_piece retirer(t_entree& e) {
	e.etat = VIDE;
	return e.contenu;
}

void poser(t_entree& e, const t_piece& p) {
	e.contenu = p;
	e.etat = OCCUPEE;
}

void poser(t_file& f, const t_piece& p) {
	f.liste[f.fin] = p;
	f.fin = (f.fin + 1) % CAPACITE_FILE_FINIE;
	f.nbPieces++;
}

void poser(t_machine& m, const t_piece& p) {
	m.contenu = p;
	m.etat = OCCUPEE;
}

void simuler_Partie1(int duree, int DA, int SA, int SB, int SC, t_systemePartie1& systeme) {
	// INITIALISATION
	const int INF = duree + 5;
	t_entree& e = systeme.e;
	t_sortie& s = systeme.s;
	t_machine& mA = systeme.mA;
	t_machine& mB = systeme.mB;
	t_machine& mC = systeme.mC;
	t_file& f = systeme.f;
	e.dpe = 0;
	mA.dpe = INF;
	mB.dpe = INF;
	mC.dpe = INF;

	// SIMULATION
	int dateSimulation = 0;
	int imin = 1;
	int iPiece = 1;
	t_piece premierePiece = { iPiece, dateSimulation };
	poser(e, premierePiece);
	while (dateSimulation < duree) {
		// chercher entité avec DPE min
		if (e.dpe < mA.dpe && e.dpe < mB.dpe && e.dpe < mC.dpe) {
			imin = 1;
		}
		else if (mA.dpe < mB.dpe && mA.dpe < mC.dpe){
			imin = 2;
		}
		else if (mB.dpe < mC.dpe) {
			imin = 3;
		}
		else {
			imin = 4;
		}

		// si DPE min dans l'entrée
		if (imin == 1) {
			// A FAIRE : Remplacer f par mA.f
			dateSimulation = e.dpe;
			t_piece nouvPiece = { iPiece, dateSimulation }; // num, dateEntreeSys
			t_piece pieceEntree = retirer(e);
			poser(e, nouvPiece);
			// Tests sur la file
			if (estPleine(f)) {
				// entrée bloquée
				e.etat = BLOQUEE;
				e.nbPiecesPerdues++;
				e.dpe = INF;
			}
			else {
				// la pièce passe en file d'attente
				e.etat = VIDE;
				e.dpe = dateSimulation + DA;
				// MAJ position et dateEntree de pieceEntree
				poser(f, pieceEntree);
				f.dateDernierePiece = dateSimulation;
				// la pièce passe dans la machine A
				mA.dpe = dateSimulation;
			}
		}
		// si DPE min dans la machine A
		if (imin == 2) {
			dateSimulation = mA.dpe;
			// sortie du système
			if (mA.etat == OCCUPEE) {
				t_piece p = retirer(mA);
				// MAJ dateSortie de p
				// Calcul de la prochaine machine où aller
				// MAJ position et dateEntree de p
				// Ajouter pièce dans file de machine obtenue
			}
			// machine bloquée
			if (estVide(f)) {
				mA.etat = BLOQUEE;
				mA.dpe = INF;
			}
			// passage de file à machine
			else {
				t_piece p = retirer(f);
				p.dateSortieFile = dateSimulation;
				// MAJ position et dateEntree machine de p
				poser(mA, p);
				mA.dpe = dateSimulation + SA;
			}

			/*if (m.etat == OCCUPEE) {
				int numPiece = retirer(m);
				t_piece& p = systeme.pieces[numPiece];
				p.dateSortieMachine = dateSimulation;
				p.dateSortieSys = dateSimulation;
				s.nbPieceSortie++;
				m.etat = VIDE;
			}
			if (estVide(f)) {
				m.dpe = INF;
			}
			else {
				int numPiece = retirer(f);
				t_piece& p = systeme.pieces[numPiece];
				p.dateSortieFile = dateSimulation;
				p.dateEntreeMachine = dateSimulation;
				if (e.etat == BLOQUEE) {
					e.dpe = dateSimulation;
				}
				poser(m, p);
				m.etat = OCCUPEE;
				m.dpe = dateSimulation + DT;
			}
			dateSimulation = mA.dpe;*/
		}
		// si DPE min dans la machine B
		if (imin == 3) {
			dateSimulation = mB.dpe;
		}
		// si DPE min dans la machine C
		if (imin == 4) {
			dateSimulation = mC.dpe;
		}
	}
}

/* A SUPPRIMER */
/*void simuler(int duree, int DA, int DT, t_systeme& systeme)
{
	// INITIALISATION
	const int INF = duree + 5;
	t_entree& e = systeme.e;
	t_sortie& s = systeme.s;
	t_machine& m = systeme.m;
	t_file& f = systeme.f;
	e.dpe = 0;
	m.dpe = INF;

	for (int i = 0; i <= NBPIECES; i++) {
		t_piece& p = systeme.pieces[i];
		p.num = i;
		p.dateEntreeFile = p.dateSortieFile =
			p.dateEntreeMachine = p.dateSortieMachine =
			p.dateEntreeSys = p.dateSortieSys = 0;
	}

	// SIMULATION
	int dateSimulation = 0;
	int imin = 1;
	int iPiece = 1;
	int poidsPiecesFile = 0;
	e.contenu = systeme.pieces[iPiece];
	while (dateSimulation < duree) {
		System::Windows::Forms::Application::DoEvents();
		// chercher entité avec DPE min
		if (e.dpe < m.dpe) {
			imin = 1;
			dateSimulation = e.dpe;
		}
		else {
			imin = 2;
			dateSimulation = m.dpe;
		}

		// si DPE min dans l'entrée
		if (imin == 1) {
			systeme.pieces[iPiece].dateEntreeSys = dateSimulation;
			// Tests sur la file
			if (estPleine(f)) {
				// entrée bloquée
				e.etat = BLOQUEE;
				e.nbPiecesPerdues++;
				e.dpe = INF;
			}
			else if (m.etat == VIDE) {
				// la pièce va directement sur la machine
				int numPiece = retirer(e);
				t_piece& p = systeme.pieces[numPiece];
				e.dpe = dateSimulation + DA;
				poser(m, p);
				p.dateEntreeMachine = dateSimulation;
				m.dpe = dateSimulation + DT;
			}
			else {
				// la pièce passe en file d'attente
				int numPiece = retirer(e);
				t_piece& p = systeme.pieces[numPiece];
				e.etat = VIDE;
				e.dpe = dateSimulation + DA;
				
				poser(f, p);
				f.nbPiecesMoyen += f.dateDernierePiece * f.nbPieces;
				poidsPiecesFile += f.dateDernierePiece;
				f.dateDernierePiece = dateSimulation;
				p.dateEntreeFile = dateSimulation;
			}

			// Ajout de nouvelle pièce dans l'entrée
			if (iPiece < NBPIECES) {
				iPiece++;
				e.contenu = systeme.pieces[iPiece];
			}
			else {
				e.dpe = INF;
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
				m.dpe = INF;
			}
			else {
				int numPiece = retirer(f);
				t_piece& p = systeme.pieces[numPiece];
				p.dateSortieFile = dateSimulation;
				p.dateEntreeMachine = dateSimulation;
				if (e.etat == BLOQUEE) {
					e.dpe = dateSimulation;
				}
				poser(m, p);
				m.etat = OCCUPEE;
				m.dpe = dateSimulation + DT;
			}
		}
	}
	// vidage de la file
	while (!estVide(f)) {
		int numPiece = retirer(f);
		t_piece& p = systeme.pieces[numPiece];
		p.dateSortieFile = dateSimulation;
		p.dateSortieSys = dateSimulation;
		p.dateSortieMachine = dateSimulation;
	}

	// CALCUL DES TEMPS MOYENS
	float& tpsMoyFile = s.tempsMoyenFile,
		& tpsTotMachine = s.tempsMoyenMachine,
		& tpsTotSys = s.tempsMoyenSys;
	for (int i = 1; i <= NBPIECES; i++) {
		System::Windows::Forms::Application::DoEvents();
		t_piece& p = systeme.pieces[i];
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
	if (poidsPiecesFile > 0)
		f.nbPiecesMoyen = (float)f.nbPiecesMoyen / poidsPiecesFile;
}*/
