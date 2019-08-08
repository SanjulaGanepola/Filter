/***************************************************************
 * Name:      FilterApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Sanjula ()
 * Created:   2019-06-11
 * Copyright: Sanjula ()
 * License:
 **************************************************************/

#include "FilterApp.h"

 //(*AppHeaders
#include "FilterMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(FilterApp);

bool FilterApp::OnInit()
{
	//(*AppInitialize
	bool wxsOK = true;
	wxInitAllImageHandlers();
	if (wxsOK)
	{
		FilterDialog Dlg(0);
		SetTopWindow(&Dlg);
		Dlg.ShowModal();
		wxsOK = false;
	}
	//*)
	return wxsOK;

}
