#include "avianApp.h"

wxIMPLEMENT_APP(avianApp);

avianApp::avianApp()
{
}

avianApp::~avianApp()
{
}

bool avianApp::OnInit()
{
	mainWindow = new avianMain();
	mainWindow->Show();
	return true;
}
