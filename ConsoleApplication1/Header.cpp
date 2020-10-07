#include "Header.h"
#include <string>

bool estPleine(const t_file& f) {
	return (f.fin + 1) % TAILLE_FILE == f.debut;
}

bool estVide(const t_file& f) {
	return f.debut == f.fin;
}

t_piece retirer(t_file& f) {
	t_piece piece = f.liste[f.debut];
	f.debut = (f.debut + 1) % TAILLE_FILE;
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

void poser(t_file& f, t_piece p) {
	f.liste[f.fin] = p;
	f.fin = (f.fin + 1) % TAILLE_FILE;
}

void poser(t_machine& m, t_piece p) {
	m.contenu = p;
	m.etat = OCCUPEE;
}

void updateSortie(t_sortie& s, t_piece p)
{
	s.nbPieceSortie++;
}


void simuler(int duree, int DA, int DT, t_systeme& systeme,
	System::Windows::Forms::RichTextBox^ zone)
{
	//System::Windows::Forms::Application::DoEvents();

	/* INITIALISATION */
	const int INF = duree + 10;
	t_entree e = { OCCUPEE };
	t_sortie s = { 0 };
	t_file f = { 0 };
	t_machine m = { VIDE };
	t_piece pieces[TAILLE_FILE] = { 0 }; // nb pièces passant par entrée
	e.dateProchainEvenement = DT;
	m.dateProchainEvenement = INF;

	for (int i = 0; i < TAILLE_FILE; i++) {
		pieces[i].num = i;
	}

	/* SIMULATION */
	int dateSimulation = 0, dateFin = INF;
	int imin = 1;
	int iPiece = 0;
	e.contenu = pieces[iPiece];
	while (dateSimulation < duree) {
		// chercher entité avec DPE min
		if (e.dateProchainEvenement < m.dateProchainEvenement) {
			imin = 1;
		}
		else {
			imin = 2;
		}

		// si DPE min dans l'entrée
		if (imin == 1) {
			dateSimulation = e.dateProchainEvenement;
			if (estPleine(f)) {
				e.etat = BLOQUEE;
				e.nbPiecesPerdues++;
				e.dateProchainEvenement = INF;
			}
			else {
				t_piece p = retirer(e);
				p.dateEntreeFile = dateSimulation;
				e.etat = VIDE;
				e.dateProchainEvenement = dateSimulation + DA;
				iPiece++;
				e.contenu = pieces[iPiece];
				poser(f, p);
			}
		}

		// si DPE min dans la machine
		if (imin == 2) {
			dateSimulation = m.dateProchainEvenement;
			t_piece p = retirer(m);
			p.dateSortieSys = dateSimulation;
			m.etat = VIDE;
			if (estVide(f)) {
				m.dateProchainEvenement = INF;
			}
			else {
				t_piece p = retirer(f);
				p.dateSortieFile = dateSimulation;
				p.dateEntreeMachine = dateSimulation;
				if (e.etat == BLOQUEE) {
					e.dateProchainEvenement = dateSimulation;
				}
				poser(m, p);
				m.dateProchainEvenement = dateSimulation + DT;
			}
		}
	}
	/* CALCUL DES TEMPS MOYENS */
	/* AFFICHAGE STATS PIECES */

}
