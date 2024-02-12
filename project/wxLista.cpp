#include "wxLista.h"
#include "packages.h"

//(*InternalHeaders(wxLista)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#undef _
#define _(s) wxString::FromUTF8(s)

//(*IdInit(wxLista)
const long wxLista::ID_LISTBOX1 = wxNewId();
const long wxLista::ID_SCROLLEDWINDOW1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxLista,wxDialog)
	//(*EventTable(wxLista)
	//*)
END_EVENT_TABLE()

wxLista::wxLista(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(wxLista)
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, _("Lista kont"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(1, 1, 0, 0);
	ScrolledWindow1 = new wxScrolledWindow(this, ID_SCROLLEDWINDOW1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_SCROLLEDWINDOW1"));
	ListBox1 = new wxListBox(ScrolledWindow1, ID_LISTBOX1, wxPoint(0,0), wxSize(400,200), 0, 0, wxVSCROLL|wxHSCROLL|wxALWAYS_SHOW_SB, wxDefaultValidator, _T("ID_LISTBOX1"));
	FlexGridSizer1->Add(ScrolledWindow1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);
	//*)
	SetIcon(wxICON(aaaa));


	wxString filename = "db.txt";
    ifstream file(filename.ToStdString());

    ListBox1->Clear();

    string line;
    wxArrayString entries;

    while (getline(file, line)) {
        istringstream iss(line);
        int number;
        string name, surname;
        double balance;

        if (iss >> number >> name >> surname >> balance) {
            wxString entry = wxString::Format("Numer konta: %d, Imie: %s, Nazwisko: %s, Saldo: %.1f",
                number, name, surname, balance);
            entries.Add(entry);
        }
    }

    file.close();

    if (!entries.IsEmpty()) {
        ListBox1->InsertItems(entries, 0);
    } else {
        ListBox1->Append("Brak wpisow w bazie danych.");
    }
}

wxLista::~wxLista()
{
	//(*Destroy(wxLista)
	//*)
}

