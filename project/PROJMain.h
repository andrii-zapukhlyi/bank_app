/***************************************************************
 * Name:      PROJMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2023-12-27
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef PROJMAIN_H
#define PROJMAIN_H

//(*Headers(PROJDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/gbsizer.h>
#include <wx/statbmp.h>
//*)

class PROJDialog: public wxDialog
{
    public:

        PROJDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~PROJDialog();

    private:

        //(*Handlers(PROJDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton5Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton1Click1(wxCommandEvent& event);
        void OnButton1Click2(wxCommandEvent& event);
        void OnButton2Click1(wxCommandEvent& event);
        void OnButton8Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        void OnButton6Click(wxCommandEvent& event);
        void OnButton7Click(wxCommandEvent& event);
        void OnInit(wxInitDialogEvent& event);
        //*)

        //(*Identifiers(PROJDialog)
        static const long ID_STATICBITMAP1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_BUTTON5;
        static const long ID_BUTTON6;
        static const long ID_BUTTON7;
        static const long ID_BUTTON8;
        //*)

        //(*Declarations(PROJDialog)
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxButton* Button4;
        wxButton* Button5;
        wxButton* Button6;
        wxButton* Button7;
        wxButton* Button8;
        wxStaticBitmap* StaticBitmap1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // PROJMAIN_H
