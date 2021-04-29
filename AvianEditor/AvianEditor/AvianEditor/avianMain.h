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
	wxTreeItemId gameAssets;	wxTreeItemId Actors;	wxTreeItemId Behavior;	wxTreeItemId MovementPatterns;	wxTreeItemId MyFunctions;	wxTreeItemId ExternalLibraries;	wxTreeItemId GlobalData;	wxTreeItemId LocalData;	wxTreeItemId game;	wxTreeItemId level;
};

