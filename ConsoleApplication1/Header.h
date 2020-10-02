#pragma once

typedef struct t_piece {
	int num;
	int dateArrivee;
	int dateSortie;
}t_piece;

typedef struct t_systeme{
	int duree_sim;
	int duree_IA;
	int duree_t;

	//t_machine m;
	//t_entree e;
	//t_file f;
	//t_sortie s;
}t_systeme;

void simuler(int duree, int DA, int DT, t_systeme& systeme, 
	System::Windows::Forms::RichTextBox^ zone);
