#include "wxWycofaj.h"
#include "packages.h"

extern string filePath;
extern string tempFilePath;
extern vector<wxString> globalComboBoxItems;

//(*InternalHeaders(wxWycofaj)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(wxWycofaj)
const long wxWycofaj::ID_STATICTEXT1 = wxNewId();
const long wxWycofaj::ID_COMBOBOX1 = wxNewId();
const long wxWycofaj::ID_STATICTEXT2 = wxNewId();
const long wxWycofaj::ID_SPINCTRLDOUBLE1 = wxNewId();
const long wxWycofaj::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxWycofaj,wxDialog)
	//(*EventTable(wxWycofaj)
	//*)
END_EVENT_TABLE()

wxWycofaj::wxWycofaj(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(wxWycofaj)
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, _("Wycofaj środki"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(3, 2, 5, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Nr konta"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox1 = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxSize(230,35), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
	FlexGridSizer1->Add(ComboBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Kwota"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SpinCtrlDouble1 = new wxSpinCtrlDouble(this, ID_SPINCTRLDOUBLE1, _T("0"), wxDefaultPosition, wxSize(230,35), 0, 0, 10000, 0, 0.01, _T("ID_SPINCTRLDOUBLE1"));
	SpinCtrlDouble1->SetValue(_T("0"));
	FlexGridSizer1->Add(SpinCtrlDouble1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("WYCOFAJ ŚRODKI"), wxDefaultPosition, wxSize(175,35), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxWycofaj::withdraw);
	//*)
	SetIcon(wxICON(aaaa));
    for (const auto& item : globalComboBoxItems) {
        ComboBox1->Append(item);
    }
}

wxWycofaj::~wxWycofaj()
{
	//(*Destroy(wxWycofaj)
	//*)
}

void wxWycofaj::withdraw(wxCommandEvent& event)
{
    if (ComboBox1->wxItemContainerImmutable::IsEmpty()) {
        wxMessageBox("Pole jest puste.", "Blad", wxICON_ERROR);
        return;
    } else if (!ComboBox1->GetValue().IsNumber()) {
        wxMessageBox("Pole numer moze zawierac tylko liczby.", "Blad", wxICON_ERROR);
        return;
    }
    int option = 0;
    int number = stoi(w2s(ComboBox1->GetValue()));
    double amount = SpinCtrlDouble1->GetValue();

    fstream file(filePath);
    ofstream tempFile(tempFilePath);
    string line;
    bool found = false;
    while (getline(file, line)) {
        istringstream iss(line);
        int currentAccountNumber;
        string name, surname;
        double balance;
        iss >> currentAccountNumber >> name >> surname >> balance;
        if (currentAccountNumber == number) {
            if (option == 1) {
                balance += amount;
                found = true;
            } else {
                if (amount <= balance) {
                    balance -= amount;
                    found = true;
                } else {
                    break;
                }
            }
        }
        tempFile << currentAccountNumber << '\t' << name << '\t' << surname << '\t' << balance << '\n';
    }
    file.close();
    tempFile.close();
    if (found && wxRenameFile(tempFilePath, filePath, true)) {
        wxMessageBox(_("Saldo zostało pomyślnie zaktualizowane."), wxMessageBoxCaptionStr, wxICON_INFORMATION);
        globalComboBoxItems.erase(std::find(globalComboBoxItems.begin(), globalComboBoxItems.end(), wxString::Format("%d", number)));
        globalComboBoxItems.insert(globalComboBoxItems.begin(), wxString::Format("%d", number));
        Close(true);
    } else {
        wxMessageBox(_("Nie znaleziono konta lub kwota jest większa od salda."), "Blad", wxICON_ERROR);
        wxRemoveFile(tempFilePath);
    }
}
