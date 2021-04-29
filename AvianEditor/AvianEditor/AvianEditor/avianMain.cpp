#include "avianMain.h"

avianMain::avianMain() : wxFrame(nullptr, wxID_ANY, "AvianEditor", wxPoint(100, 100), wxSize(1280, 720) )
{
	gameTree = new wxTreeCtrl(this, wxID_ANY, wxPoint(16, 48), wxSize(376, 224), wxTR_HIDE_ROOT + wxTR_HAS_BUTTONS, wxDefaultValidator, _T("PROJECTTREE")); //new wxTreeCtrl(this, wxID_ANY);//, wxPoint(5, 5), wxSize(300, 700));
	root = gameTree->AddRoot(_T("Root"), 0);	gameAssets = gameTree->AppendItem(root, _T("Game Assets"), 0);	game = gameTree->AppendItem(root, _T("Game"), 0);	Actors = gameTree->AppendItem(gameAssets, _T("Actors"), 0);	Behavior = gameTree->AppendItem(gameAssets, _T("Behavior"), 0);	gameTree->AppendItem(Behavior, _T("State Machines"), 1);	gameTree->AppendItem(Behavior, _T("Object Functions"), 1);	MovementPatterns = gameTree->AppendItem(gameAssets, _T("Movement Patterns"), 0);
	MyFunctions = gameTree->AppendItem(gameAssets, _T("My Functions"), 0);
	ExternalLibraries = gameTree->AppendItem(gameAssets, _T("External Libraries"), 0);
	GlobalData = gameTree->AppendItem(gameAssets, _T("Global Data"), 0);
	LocalData = gameTree->AppendItem(gameAssets, _T("Local Data"), 0);
	level = gameTree->AppendItem(game, _T("Level_1"), 0);
	gameTree->AppendItem(level, _T("Cursor"), 1);	gameTree->AppendItem(level, _T("Maps"), 1);
	gameTree->AppendItem(level, _T("Sprites"), 1);
	gameTree->AppendItem(level, _T("Particle Systems"), 1);
	gameTree->AppendItem(level, _T("Sound"), 1);
	gameTree->AppendItem(level, _T("Text Objects"), 1);
	gameTree->AppendItem(level, _T("Variables"), 1);




	gameTree->ExpandAll();
}

avianMain::~avianMain()
{
}
