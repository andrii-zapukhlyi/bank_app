#ifndef WXDEPOZYT_H
#define WXDEPOZYT_H

//(*Headers(wxDepozyt)
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>
//*)

#undef _
#define _(s) wxString::FromUTF8(s)

class wxDepozyt: public wxDialog
{
	public:

		wxDepozyt(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~wxDepozyt();

		//(*Declarations(wxDepozyt)
		wxButton* Button1;
		wxComboBox* ComboBox1;
		wxSpinCtrlDouble* SpinCtrlDouble1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		//*)

	protected:

		//(*Identifiers(wxDepozyt)
		static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX1;
		static const long ID_STATICTEXT2;
		static const long ID_SPINCTRLDOUBLE1;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(wxDepozyt)
		void deposit(wxCommandEvent& event);
		void OnTextCtrl1Text(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
