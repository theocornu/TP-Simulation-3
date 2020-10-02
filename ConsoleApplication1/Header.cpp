#include "Header.h"

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
	for (int i = 1; i <= 100000; i++) {
		System::Windows::Forms::Application::DoEvents();
	}
}
