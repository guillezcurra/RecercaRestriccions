#pragma once
#include "wx/wx.h"

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

private:
	//declaració de la barra del menú
	wxMenuBar *menu_horitzontal = nullptr;
	//declaració de cada menu
	wxMenu *menu_fitxer = nullptr;
	wxMenu *menu_ajuda = nullptr;
};

