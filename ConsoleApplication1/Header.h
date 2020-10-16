#pragma once

const int TAILLE_FILE = 10; // 1 case vide pour fin de file
const int NBPIECES = 10000;

enum t_etat
{
	VIDE,
	OCCUPEE,
	BLOQUEE
};


typedef struct t_piece
{
	// int id; POUR REMPLACER NUM
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
	t_piece contenu;
	int dateProchainEvenement;
	int nbPiecesPerdues;
}t_entree;


typedef struct t_file
{
	t_piece liste[TAILLE_FILE];
	int debut;
	int fin;
	int dateDernierePiece;
	int nbPieces;
	float nbPiecesMoyen;
}t_file;


typedef struct t_machine
{
	// int id;
	t_etat etat;
	// int idMachineBloquee;
	t_piece contenu;
	int dateProchainEvenement;
}t_machine;


typedef struct t_sortie
{
	int nbPieceSortie;
	float tempsMoyenSys;
	float tempsMoyenFile;
	float tempsMoyenMachine;
}t_sortie;


typedef struct t_systeme{
	t_machine m;
	// t_machine m[3];
	t_entree e;
	t_file f;
	t_sortie s;
	t_piece pieces[NBPIECES+1];
}t_systeme;


int retirer(t_entree& e);
int retirer(t_machine& m);
int retirer(t_file& f);
bool estPleine(const t_file& f);
bool estVide(const t_file& f);
void poser(t_file& f,const t_piece& p);
void poser(t_machine& m, const t_piece& p);
void simuler(int duree, int DA, int DT, t_systeme& systeme);
