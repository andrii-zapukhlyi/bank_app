#ifndef WXLISTA_H
#define WXLISTA_H

//(*Headers(wxLista)
#include <wx/dialog.h>
#include <wx/listbox.h>
#include <wx/scrolwin.h>
#include <wx/sizer.h>
//*)

class wxLista: public wxDialog
{
	public:

		wxLista(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~wxLista();

		//(*Declarations(wxLista)
		wxListBox* ListBox1;
		wxScrolledWindow* ScrolledWindow1;
		//*)

	protected:

		//(*Identifiers(wxLista)
		static const long ID_LISTBOX1;
		static const long ID_SCROLLEDWINDOW1;
		//*)

	private:

		//(*Handlers(wxLista)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
