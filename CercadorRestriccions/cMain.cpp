#include "cMain.h"


//wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	
//wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Gestió de restriccions", wxPoint(30,30), wxSize(800, 600))
{
	// ---------- MENU ----------
	// aquí crearem els botons, camps, llistes etc...
	menu_horitzontal = new wxMenuBar();
	// afegim opcions a cadascun dels menús, després de crear-los.
	menu_fitxer = new wxMenu();
	menu_fitxer->Append(wxID_OPEN, _T("&Obre"));
	menu_fitxer->Append(wxID_SAVE, _T("&Desa"));
	//afegir el menú fitxer a la barra de menús
	menu_horitzontal->Append(menu_fitxer, _T("&Fitxer"));
	menu_ajuda = new wxMenu();
	menu_ajuda->Append(wxID_ABOUT, _T("&Quant a..."));
	menu_horitzontal->Append(menu_ajuda, _T("&Ajuda"));

	//Afegir la barra de menú al wxFrame
	SetMenuBar(menu_horitzontal);
	// ---------- FI MENU ----------

}

cMain::~cMain()
{
}
