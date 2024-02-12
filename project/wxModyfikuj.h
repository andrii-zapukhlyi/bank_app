#ifndef WXMODYFIKUJ_H
#define WXMODYFIKUJ_H

//(*Headers(wxModyfikuj)
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

#undef _
#define _(s) wxString::FromUTF8(s)

class wxModyfikuj: public wxDialog
{
	public:

		wxModyfikuj(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~wxModyfikuj();

		//(*Declarations(wxModyfikuj)
		wxButton* Button1;
		wxComboBox* ComboBox1;
		wxSpinCtrlDouble* SpinCtrlDouble1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl3;
		//*)

	protected:

		//(*Identifiers(wxModyfikuj)
		static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT6;
		static const long ID_SPINCTRLDOUBLE1;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(wxModyfikuj)
		void modify_account(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
