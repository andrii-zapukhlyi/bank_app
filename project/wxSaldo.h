#ifndef WXSALDO_H
#define WXSALDO_H

//(*Headers(wxSaldo)
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
//*)

#undef _
#define _(s) wxString::FromUTF8(s)

class wxSaldo: public wxDialog
{
	public:

		wxSaldo(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~wxSaldo();

		//(*Declarations(wxSaldo)
		wxButton* Button1;
		wxComboBox* ComboBox1;
		wxStaticText* StaticText1;
		//*)

	protected:

		//(*Identifiers(wxSaldo)
		static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX1;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(wxSaldo)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton1Click1(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
