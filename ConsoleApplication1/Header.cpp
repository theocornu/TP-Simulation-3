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

void poser(t_file& f, t_piece p) {
	f.liste[f.fin] = p;
	f.fin = (f.fin + 1) % TAILLE_FILE;
}

void poser(t_machine& m, t_piece p) {
	m.contenu = p;
	m.etat = OCCUPEE;
}


void simuler(int duree, int DA, int DT, t_systeme& systeme,
	System::Windows::Forms::RichTextBox^ zone)
{
	//System::Windows::Forms::Application::DoEvents();

	/* INITIALISATION */
	const int INF = duree + 10;
	const int NBPIECES = 17;
	t_entree e = { OCCUPEE };
	t_sortie s = { 0 };
	t_file f = { 0 };
	t_machine m = { VIDE };
	t_piece pieces[NBPIECES+1] = { 0 }; // nb pièces passant par entrée
	e.dateProchainEvenement = 0;
	m.dateProchainEvenement = INF;

	for (int i = 0; i <= NBPIECES; i++) {
		pieces[i].num = i;
	}

	/* SIMULATION */
	int dateSimulation = 0;
	int imin = 1;
	int iPiece = 1;
	e.contenu = pieces[iPiece];
	while (dateSimulation < duree) {
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
			pieces[iPiece].dateEntreeSys = dateSimulation;
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
				e.dateProchainEvenement = dateSimulation + DA;
				poser(m, pieces[numPiece]);
				pieces[numPiece].dateEntreeMachine = dateSimulation;
				m.dateProchainEvenement = dateSimulation + DT;
			}
			else {
				// la pièce passe en file d'attente
				int numPiece = retirer(e);
				e.etat = VIDE;
				e.dateProchainEvenement = dateSimulation + DA;
				poser(f, pieces[numPiece]);
				pieces[numPiece].dateEntreeFile = dateSimulation;
			}

			// Ajout de nouvelle pièce dans l'entrée
			if (iPiece < NBPIECES) {
				iPiece++;
				e.contenu = pieces[iPiece];
			}
			else {
				e.dateProchainEvenement = INF;
			}
		}

		// si DPE min dans la machine
		if (imin == 2) {
			if (m.etat == OCCUPEE) {
				int numPiece = retirer(m);
				pieces[numPiece].dateSortieMachine = dateSimulation;
				pieces[numPiece].dateSortieSys = dateSimulation;
				s.nbPieceSortie++;
				m.etat = VIDE;
			}
			if (estVide(f)) {
				m.dateProchainEvenement = INF;
			}
			else {
				int numPiece = retirer(f);
				pieces[numPiece].dateSortieFile = dateSimulation;
				pieces[numPiece].dateEntreeMachine = dateSimulation;
				if (e.etat == BLOQUEE) {
					e.dateProchainEvenement = dateSimulation;
				}
				poser(m, pieces[numPiece]);
				m.etat = OCCUPEE;
				m.dateProchainEvenement = dateSimulation + DT;
			}
		}
	}
	/* CALCUL DES TEMPS MOYENS */
	int tpsTotFile = 0, tpsTotMachine = 0, tpsTotSys = 0;
	for (int i = 1; i <= NBPIECES; i++) {
		t_piece p = pieces[i];
		// si la pièce n'a pas été perdue
		if (p.dateSortieSys != 0) {
			tpsTotFile += (p.dateSortieFile - p.dateEntreeFile);
			tpsTotMachine += (p.dateSortieMachine - p.dateEntreeMachine);
			tpsTotSys += (p.dateSortieSys - p.dateEntreeSys);
		}
	}
	tpsTotFile /= s.nbPieceSortie;
	tpsTotMachine /= s.nbPieceSortie;
	tpsTotSys /= s.nbPieceSortie;
	/* AFFICHAGE STATS PIECES */
	System::String^ donneeSysteme = "TempsMoyenDeSejourDansLeSysteme = " +
		tpsTotSys + "\n" + "TempsMoyenDeSejourDansLaFile = " + tpsTotFile + "\n" +
		"TempsMoyenDeSejourSurLaMachine = " + tpsTotMachine + "\n";
	zone->AppendText(donneeSysteme);
	for (int i = 1; i <= NBPIECES; i++) {
		System::String^ donneePiece = "" + pieces[i].num + " " + 
			pieces[i].dateEntreeSys + " " + pieces[i].dateSortieSys + "\n";
		zone->AppendText(donneePiece);
	}
	zone->AppendText("Fin de simulation.");
}
