#pragma once
#include "wx/wx.h"
#include <wx/treectrl.h>

class avianMain : public wxFrame
{
public:
	avianMain();
	~avianMain();
	wxTreeCtrl* gameTree = nullptr;
	wxTreeItemId root;
	wxTreeItemId gameAssets;
};
