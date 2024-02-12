#ifndef WXWYCOFAJ_H
#define WXWYCOFAJ_H

//(*Headers(wxWycofaj)
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>
//*)

#undef _
#define _(s) wxString::FromUTF8(s)

class wxWycofaj: public wxDialog
{
	public:

		wxWycofaj(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~wxWycofaj();

		//(*Declarations(wxWycofaj)
		wxButton* Button1;
		wxComboBox* ComboBox1;
		wxSpinCtrlDouble* SpinCtrlDouble1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		//*)

	protected:

		//(*Identifiers(wxWycofaj)
		static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX1;
		static const long ID_STATICTEXT2;
		static const long ID_SPINCTRLDOUBLE1;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(wxWycofaj)
		void withdraw(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
