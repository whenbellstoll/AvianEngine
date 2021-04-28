#pragma once

#include "wx/wx.h"
#include "avianMain.h"

class avianApp : public wxApp
{
public:
	avianApp();
	~avianApp();
	avianMain* mainWindow = nullptr;
	virtual bool OnInit();

};

