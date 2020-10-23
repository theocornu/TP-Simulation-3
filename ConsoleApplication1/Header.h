#pragma once

const int CAPACITE_FILE_FINIE = 10;
const int CAPACITE_FILE_INFINIE = 1000;
const int CAPACITE_SORTIE = 50;
const int NBPOSITIONS = 12;
const int NBPIECES = 10000;

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
	int dateSortieSys;
	int dateEntree[NBPOSITIONS];
	int dateSortie[NBPOSITIONS];
	int position[NBPOSITIONS]; // numéro de machine
}t_piece;


typedef struct t_entree {
	t_etat etat;
	t_piece contenu;
	int dpe;
	int nbPiecesPerdues;
}t_entree;


typedef struct t_file
{
	t_piece liste[CAPACITE_FILE_FINIE+1]; // 1 case vide pour fin de file
	int debut;
	int fin;
	int dateDernierePiece;
	int nbPieces;
	float nbPiecesMoyen;
}t_file;


typedef struct t_machine
{
	t_etat etat;
	int idMachineBloquee;
	t_piece contenu;
	int dpe;
}t_machine;


typedef struct t_sortie
{
	int nbPieceSortie;
	float tempsMoyenSys;
	float tempsMoyenFile;
	float tempsMoyenMachine;
	t_piece pieces[CAPACITE_SORTIE+1];
}t_sortie;


typedef struct t_systeme{
	t_machine m;
	t_entree e;
	t_file f;
	t_sortie s;
	t_piece pieces[NBPIECES+1];
}t_systeme;

// A FAIRE : Fusionner machine et file
typedef struct t_systemePartie1{
	t_machine mA;
	t_machine mB;
	t_machine mC;
	t_entree e;
	t_file f;
	t_sortie s;
}t_systemePartie1;


t_piece retirer(t_entree& e);
t_piece retirer(t_machine& m);
t_piece retirer(t_file& f);
bool estPleine(const t_file& f);
bool estVide(const t_file& f);
void poser(t_entree& e, const t_piece& p);
void poser(t_file& f,const t_piece& p);
void poser(t_machine& m, const t_piece& p);
void simuler(int duree, int DA, int SA, int SB, int SC, t_systeme& systeme);
