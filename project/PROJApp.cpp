/***************************************************************
 * Name:      PROJApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2023-12-27
 * Copyright:  ()
 * License:
 **************************************************************/

#include "PROJApp.h"

//(*AppHeaders
#include "PROJMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(PROJApp);

bool PROJApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	PROJDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
