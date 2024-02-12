#include "wxSaldo.h"
#include <wx/msgdlg.h>
#include "packages.h"
#include <iomanip>

extern string filePath;
extern vector<wxString> globalComboBoxItems;


//(*InternalHeaders(wxSaldo)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(wxSaldo)
const long wxSaldo::ID_STATICTEXT1 = wxNewId();
const long wxSaldo::ID_COMBOBOX1 = wxNewId();
const long wxSaldo::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxSaldo,wxDialog)
	//(*EventTable(wxSaldo)
	//*)
END_EVENT_TABLE()

wxSaldo::wxSaldo(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(wxSaldo)
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, _("Sprawdź saldo konta"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(2, 2, 5, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Nr konta"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox1 = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxSize(230,35), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
	FlexGridSizer1->Add(ComboBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("POKAŻ STAN KONTA"), wxDefaultPosition, wxSize(175,35), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxSaldo::OnButton1Click);
	//*)
	SetIcon(wxICON(aaaa));
    for (const auto& item : globalComboBoxItems) {
        ComboBox1->Append(item);
    }
}

wxSaldo::~wxSaldo()
{
	//(*Destroy(wxSaldo)
	//*)
}


void wxSaldo::OnButton1Click(wxCommandEvent& event)
{
    if (ComboBox1->wxItemContainerImmutable::IsEmpty()) {
        wxMessageBox("Pole jest puste.", "Blad", wxICON_ERROR);
        return;
    } else if (!ComboBox1->GetValue().IsNumber()) {
        wxMessageBox("Pole numer moze zawierac tylko liczby.", "Blad", wxICON_ERROR);
        return;
    }
    int num = stoi(w2s(ComboBox1->GetValue()));
    ifstream file(filePath);
    string line;
    bool found = false;
    while (getline(file, line)) {
        istringstream iss(line);
        int currentAccountNumber;
        string name, surname;
        double balance;
        iss >> currentAccountNumber >> name >> surname >> balance;
            if (currentAccountNumber == num) {
                wxString balanceString = wxString::Format(_("%.1f"), balance);
                wxMessageBox(_("Saldo: ") + balanceString, wxMessageBoxCaptionStr, wxICON_INFORMATION);
                found = true;
                globalComboBoxItems.erase(std::find(globalComboBoxItems.begin(), globalComboBoxItems.end(), wxString::Format("%d", num)));
                globalComboBoxItems.insert(globalComboBoxItems.begin(), wxString::Format("%d", num));
                Close(true);
                break;
            }
        }
    file.close();
    if (!found) {
       wxMessageBox(_("Konto nie znalezione."), "Error", wxICON_ERROR);
    }
}
