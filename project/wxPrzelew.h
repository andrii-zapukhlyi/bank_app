#ifndef WXPRZELEW_H
#define WXPRZELEW_H

//(*Headers(wxPrzelew)
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>
//*)

#undef _
#define _(s) wxString::FromUTF8(s)

class wxPrzelew: public wxDialog
{
	public:

		wxPrzelew(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~wxPrzelew();

		//(*Declarations(wxPrzelew)
		wxButton* Button1;
		wxComboBox* ComboBox1;
		wxComboBox* ComboBox2;
		wxSpinCtrlDouble* SpinCtrlDouble1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		//*)

	protected:

		//(*Identifiers(wxPrzelew)
		static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX1;
		static const long ID_STATICTEXT2;
		static const long ID_COMBOBOX2;
		static const long ID_STATICTEXT3;
		static const long ID_SPINCTRLDOUBLE1;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(wxPrzelew)
		void transaction(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
