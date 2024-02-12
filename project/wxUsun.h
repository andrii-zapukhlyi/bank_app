#ifndef WXUSUN_H
#define WXUSUN_H

//(*Headers(wxUsun)
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
//*)

#undef _
#define _(s) wxString::FromUTF8(s)

class wxUsun: public wxDialog
{
	public:

		wxUsun(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~wxUsun();

		//(*Declarations(wxUsun)
		wxButton* Button1;
		wxComboBox* ComboBox1;
		wxStaticText* StaticText1;
		//*)

	protected:

		//(*Identifiers(wxUsun)
		static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX1;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(wxUsun)
		void OnButton1Click(wxCommandEvent& event);
		void delete_account(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
