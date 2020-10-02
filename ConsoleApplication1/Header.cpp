#include "Header.h"

void simuler(int duree, int DA, int DT, t_systeme& systeme,
	System::Windows::Forms::RichTextBox^ zone)
{
	for (int i = 1; i <= 10000000; i++) {
		zone->AppendText("boucle");
		System::Windows::Forms::Application::DoEvents();
	}
}
