#include "wxModyfikuj.h"
#include "packages.h"

extern string filePath;
extern string tempFilePath;
extern vector<wxString> globalComboBoxItems;


//(*InternalHeaders(wxModyfikuj)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(wxModyfikuj)
const long wxModyfikuj::ID_STATICTEXT1 = wxNewId();
const long wxModyfikuj::ID_COMBOBOX1 = wxNewId();
const long wxModyfikuj::ID_STATICTEXT2 = wxNewId();
const long wxModyfikuj::ID_STATICTEXT3 = wxNewId();
const long wxModyfikuj::ID_STATICTEXT4 = wxNewId();
const long wxModyfikuj::ID_TEXTCTRL2 = wxNewId();
const long wxModyfikuj::ID_STATICTEXT5 = wxNewId();
const long wxModyfikuj::ID_TEXTCTRL3 = wxNewId();
const long wxModyfikuj::ID_STATICTEXT6 = wxNewId();
const long wxModyfikuj::ID_SPINCTRLDOUBLE1 = wxNewId();
const long wxModyfikuj::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxModyfikuj,wxDialog)
	//(*EventTable(wxModyfikuj)
	//*)
END_EVENT_TABLE()

wxModyfikuj::wxModyfikuj(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(wxModyfikuj)
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Modyfikuj dane konta"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(6, 2, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Nr konta"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox1 = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxSize(230,35), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
	FlexGridSizer1->Add(ComboBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Nowe dane"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Imię"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(230,35), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	FlexGridSizer1->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Nazwisko"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer1->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(230,35), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	FlexGridSizer1->Add(TextCtrl3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Saldo"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	FlexGridSizer1->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SpinCtrlDouble1 = new wxSpinCtrlDouble(this, ID_SPINCTRLDOUBLE1, _T("0"), wxDefaultPosition, wxSize(230,35), 0, 0, 1e+08, 0, 0.01, _T("ID_SPINCTRLDOUBLE1"));
	SpinCtrlDouble1->SetValue(_T("0"));
	FlexGridSizer1->Add(SpinCtrlDouble1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("MODYFIKUJ"), wxDefaultPosition, wxSize(175,35), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxModyfikuj::modify_account);
	//*)
	SetIcon(wxICON(aaaa));
    for (const auto& item : globalComboBoxItems) {
        ComboBox1->Append(item);
    }
}

wxModyfikuj::~wxModyfikuj()
{
	//(*Destroy(wxModyfikuj)
	//*)
}


void wxModyfikuj::modify_account(wxCommandEvent& event)
{
    if (ComboBox1->wxItemContainerImmutable::IsEmpty() || TextCtrl2->IsEmpty() || TextCtrl3->IsEmpty()) {
        wxMessageBox("Pole jest puste.", "Blad", wxICON_ERROR);
        return;
    } else if (!ComboBox1->GetValue().IsNumber()) {
        wxMessageBox("Pole numer moze zawierac tylko liczby.", "Blad", wxICON_ERROR);
        return;
    }
    int num = stoi(w2s(ComboBox1->GetValue()));
    int new_balance = SpinCtrlDouble1->GetValue();
    string new_name = w2s(TextCtrl2->GetValue());
    string new_surname = w2s(TextCtrl3->GetValue());
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
        if (currentAccountNumber == num) {
            found = true;
            tempFile << currentAccountNumber << '\t' << new_name << '\t' << new_surname << '\t' << new_balance << '\n';
        } else {
            tempFile << currentAccountNumber << '\t' << name << '\t' << surname << '\t' << balance << '\n';
        }
    }
    file.close();
    tempFile.close();
    if (found && wxRenameFile(tempFilePath, filePath, true)) {
        wxMessageBox(_("Konto zostało pomyślnie zmodyfikowane."), wxMessageBoxCaptionStr, wxICON_INFORMATION);
        globalComboBoxItems.erase(std::find(globalComboBoxItems.begin(), globalComboBoxItems.end(), wxString::Format("%d", num)));
        globalComboBoxItems.insert(globalComboBoxItems.begin(), wxString::Format("%d", num));
        Close(true);
    } else {
        wxMessageBox(_("Nie znaleziono konta lub wystąpił błąd podczas modyfikowania konta."), "Error", wxICON_ERROR);
        wxRemoveFile(tempFilePath);
    }
}
