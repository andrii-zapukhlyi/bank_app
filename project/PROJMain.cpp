/***************************************************************
 * Name:      PROJMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2023-12-27
 * Copyright:  ()
 * License:
 **************************************************************/

#include "PROJMain.h"
#include <wx/msgdlg.h>
#include "wxNewUser.h"
#include "wxDepozyt.h"
#include "wxWycofaj.h"
#include "wxPrzelew.h"
#include "wxSaldo.h"
#include "wxModyfikuj.h"
#include "wxUsun.h"
#include "wxLista.h"
#include <wx/mstream.h>
#include "image_data.h"


#undef _
#define _(s) wxString::FromUTF8(s)


//(*InternalHeaders(PROJDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(PROJDialog)
const long PROJDialog::ID_STATICBITMAP1 = wxNewId();
const long PROJDialog::ID_BUTTON1 = wxNewId();
const long PROJDialog::ID_BUTTON2 = wxNewId();
const long PROJDialog::ID_BUTTON3 = wxNewId();
const long PROJDialog::ID_BUTTON4 = wxNewId();
const long PROJDialog::ID_BUTTON5 = wxNewId();
const long PROJDialog::ID_BUTTON6 = wxNewId();
const long PROJDialog::ID_BUTTON7 = wxNewId();
const long PROJDialog::ID_BUTTON8 = wxNewId();
//*)

BEGIN_EVENT_TABLE(PROJDialog,wxDialog)
    //(*EventTable(PROJDialog)
    //*)
END_EVENT_TABLE()

PROJDialog::PROJDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(PROJDialog)
    wxGridBagSizer* GridBagSizer1;

    Create(parent, wxID_ANY, _("Aplikacja bankowa"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    GridBagSizer1 = new wxGridBagSizer(0, 0);
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxNullBitmap, wxDefaultPosition, wxSize(200,161), 0, _T("ID_STATICBITMAP1"));
    GridBagSizer1->Add(StaticBitmap1, wxGBPosition(0, 0), wxGBSpan(1, 3), wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(this, ID_BUTTON1, _("NOWY UŻYTKOWNIK"), wxDefaultPosition, wxSize(230,35), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    GridBagSizer1->Add(Button1, wxGBPosition(1, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("DEPOZYT"), wxDefaultPosition, wxSize(230,35), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    GridBagSizer1->Add(Button2, wxGBPosition(1, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button3 = new wxButton(this, ID_BUTTON3, _("WYCOFAJ ŚRODKI"), wxDefaultPosition, wxSize(230,35), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    GridBagSizer1->Add(Button3, wxGBPosition(2, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button4 = new wxButton(this, ID_BUTTON4, _("ZLEĆ PRZELEW"), wxDefaultPosition, wxSize(230,35), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    GridBagSizer1->Add(Button4, wxGBPosition(2, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button5 = new wxButton(this, ID_BUTTON5, _("SALDO KONTA"), wxDefaultPosition, wxSize(230,35), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    GridBagSizer1->Add(Button5, wxGBPosition(3, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button6 = new wxButton(this, ID_BUTTON6, _("LISTA KONT"), wxDefaultPosition, wxSize(230,35), 0, wxDefaultValidator, _T("ID_BUTTON6"));
    GridBagSizer1->Add(Button6, wxGBPosition(3, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button7 = new wxButton(this, ID_BUTTON7, _("MODYFIKUJ INFORMACJE"), wxDefaultPosition, wxSize(230,35), 0, wxDefaultValidator, _T("ID_BUTTON7"));
    GridBagSizer1->Add(Button7, wxGBPosition(4, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button8 = new wxButton(this, ID_BUTTON8, _("USUŃ KONTO"), wxDefaultPosition, wxSize(230,35), 0, wxDefaultValidator, _T("ID_BUTTON8"));
    GridBagSizer1->Add(Button8, wxGBPosition(4, 1), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(GridBagSizer1);
    GridBagSizer1->Fit(this);
    GridBagSizer1->SetSizeHints(this);
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PROJDialog::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PROJDialog::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PROJDialog::OnButton3Click);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PROJDialog::OnButton4Click);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PROJDialog::OnButton5Click);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PROJDialog::OnButton6Click);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PROJDialog::OnButton7Click);
    Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PROJDialog::OnButton8Click);
    Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&PROJDialog::OnInit);
    //*)
    wxMemoryInputStream stream(image_jpeg, sizeof(image_jpeg));
    wxImage image(stream, wxBITMAP_TYPE_JPEG);
    StaticBitmap1->SetBitmap(image);
    SetIcon(wxICON(aaaa));
}


PROJDialog::~PROJDialog()
{
    //(*Destroy(PROJDialog)
    //*)
}

void PROJDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void PROJDialog::OnAbout(wxCommandEvent& event)
{
    //wxString msg = wxbuildinfo(long_f);
    //wxMessageBox(msg, _("Welcome to..."));
}


void PROJDialog::OnButton1Click(wxCommandEvent& event)
{
    wxNewUser *okno = new wxNewUser(this);

    okno->ShowModal();
}

void PROJDialog::OnButton2Click(wxCommandEvent& event)
{
    wxDepozyt *okno = new wxDepozyt(this);

    okno->ShowModal();
}

void PROJDialog::OnButton3Click(wxCommandEvent& event)
{
    wxWycofaj *okno = new wxWycofaj(this);

    okno->ShowModal();
}

void PROJDialog::OnButton4Click(wxCommandEvent& event)
{
    wxPrzelew *okno = new wxPrzelew(this);

    okno->ShowModal();
}

void PROJDialog::OnButton5Click(wxCommandEvent& event)
{
    wxSaldo *okno = new wxSaldo(this);

    okno->ShowModal();
}

void PROJDialog::OnButton6Click(wxCommandEvent& event)
{
    wxLista *okno = new wxLista(this);

    okno->ShowModal();
}

void PROJDialog::OnButton7Click(wxCommandEvent& event)
{
    wxModyfikuj *okno = new wxModyfikuj(this);

    okno->ShowModal();
}


void PROJDialog::OnButton8Click(wxCommandEvent& event)
{
  wxUsun *okno = new wxUsun(this);

    okno->ShowModal();
}

void PROJDialog::OnInit(wxInitDialogEvent& event)
{
}
