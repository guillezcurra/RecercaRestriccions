#pragma once
#include "wx/wx.h"

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

private:
	//declaraci� de la barra del men�
	wxMenuBar *menu_horitzontal = nullptr;
	//declaraci� de cada menu
	wxMenu *menu_fitxer = nullptr;
	wxMenu *menu_ajuda = nullptr;
};

