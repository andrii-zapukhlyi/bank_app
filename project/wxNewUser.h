#ifndef WXNEWUSER_H
#define WXNEWUSER_H

//(*Headers(wxNewUser)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

#undef _
#define _(s) wxString::FromUTF8(s)

class wxNewUser: public wxDialog
{
	public:

		wxNewUser(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~wxNewUser();

		//(*Declarations(wxNewUser)
		wxButton* Button1;
		wxSpinCtrlDouble* SpinCtrlDouble1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl3;
		//*)

	protected:

		//(*Identifiers(wxNewUser)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT4;
		static const long ID_SPINCTRLDOUBLE1;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(wxNewUser)
		void create_account(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
