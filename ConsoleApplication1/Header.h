#pragma once

const int TAILLE_FILE = 10; // 1 case vide pour fin de file

enum t_etat
{
	VIDE,
	OCCUPEE,
	BLOQUEE
};


typedef struct t_piece
{
	int num;
	int dateEntreeSys;
	int dateEntreeFile;
	int dateSortieFile;
	int dateEntreeMachine;
	int dateSortieMachine;
	int dateSortieSys;
}t_piece;


typedef struct t_entree {
	t_etat etat;
	struct t_piece contenu;
	int dateProchainEvenement;
	int nbPiecesPerdues;
}t_entree;


typedef struct t_file
{
	struct t_piece liste[TAILLE_FILE];
	int debut;
	int fin;
}t_file;


typedef struct t_machine
{
	t_etat etat;
	struct t_piece contenu;
	int dateProchainEvenement;
}t_machine;


typedef struct t_sortie
{
	int nbPieceSortie;
	int tempsMoyenSys;
	int tempsMoyenFile;
	int tempsMoyenMachine;
}t_sortie;


typedef struct t_systeme{
	t_machine m;
	t_entree e;
	t_file f;
	t_sortie s;
}t_systeme;


t_piece retirer(t_entree& e);
t_piece retirer(t_machine& m);
t_piece retirer(t_file& f);
bool estPleine(const t_file& f);
bool estVide(const t_file& f);
void poser(t_file& f, t_piece p);
void poser(t_machine& m, t_piece p);
void updateSortie(t_sortie& s, t_piece p);
void simuler(int duree, int DA, int DT, t_systeme& systeme, 
	System::Windows::Forms::RichTextBox^ zone);
