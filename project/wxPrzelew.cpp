#include "wxPrzelew.h"
#include "packages.h"

extern string filePath;
extern string tempFilePath;
extern vector<wxString> globalComboBoxItems;


//(*InternalHeaders(wxPrzelew)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(wxPrzelew)
const long wxPrzelew::ID_STATICTEXT1 = wxNewId();
const long wxPrzelew::ID_COMBOBOX1 = wxNewId();
const long wxPrzelew::ID_STATICTEXT2 = wxNewId();
const long wxPrzelew::ID_COMBOBOX2 = wxNewId();
const long wxPrzelew::ID_STATICTEXT3 = wxNewId();
const long wxPrzelew::ID_SPINCTRLDOUBLE1 = wxNewId();
const long wxPrzelew::ID_BUTTON1 = wxNewId();
//*)


BEGIN_EVENT_TABLE(wxPrzelew,wxDialog)
	//(*EventTable(wxPrzelew)
	//*)
END_EVENT_TABLE()

wxPrzelew::wxPrzelew(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(wxPrzelew)
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Zleć przelew"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(4, 2, 5, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Nr konta nadawcy"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox1 = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxSize(230,35), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
	FlexGridSizer1->Add(ComboBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Nr konta odbiorcy"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox2 = new wxComboBox(this, ID_COMBOBOX2, wxEmptyString, wxDefaultPosition, wxSize(230,35), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX2"));
	FlexGridSizer1->Add(ComboBox2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Kwota"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SpinCtrlDouble1 = new wxSpinCtrlDouble(this, ID_SPINCTRLDOUBLE1, _T("0"), wxDefaultPosition, wxSize(230,35), 0, 0, 999999, 0, 0.01, _T("ID_SPINCTRLDOUBLE1"));
	SpinCtrlDouble1->SetValue(_T("0"));
	FlexGridSizer1->Add(SpinCtrlDouble1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("WYKONAJ PRZELEW"), wxDefaultPosition, wxSize(200,35), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxPrzelew::transaction);
	//*)
	SetIcon(wxICON(aaaa));
    for (const auto& item : globalComboBoxItems) {
        ComboBox1->Append(item);
        ComboBox2->Append(item);
    }
}

wxPrzelew::~wxPrzelew()
{
	//(*Destroy(wxPrzelew)
	//*)
}

void wxPrzelew::transaction(wxCommandEvent& event)
{
    if (ComboBox1->wxItemContainerImmutable::IsEmpty() || ComboBox2->wxItemContainerImmutable::IsEmpty()) {
        wxMessageBox("Pole jest puste.", "Blad", wxICON_ERROR);
        return;
    } else if (!ComboBox1->GetValue().IsNumber() || !ComboBox2->GetValue().IsNumber()) {
        wxMessageBox("Pole numer moze zawierac tylko liczby.", "Blad", wxICON_ERROR);
        return;
    }
    int num = stoi(w2s(ComboBox1->GetValue()));
    int recipient = stoi(w2s(ComboBox2->GetValue()));
    double amount = SpinCtrlDouble1->GetValue();
    fstream file(filePath);
    ofstream tempFile(tempFilePath);
    string line;
    bool sourceAccountFound = false;
    bool destinationAccountFound = false;
    double sourceBalance;
    while (getline(file, line)) {
        istringstream iss(line);
        int currentAccountNumber;
        string name, surname;
        double balance;
        iss >> currentAccountNumber >> name >> surname >> balance;
        if (currentAccountNumber == num) {
            sourceAccountFound = true;
            sourceBalance = balance;
            if (amount <= sourceBalance) {
                balance -= amount;
                tempFile << currentAccountNumber << '\t' << name << '\t' << surname << '\t' << balance << '\n';
            } else {
                wxMessageBox(_("Konto źródłowe nie ma wystarczającego salda dla transakcji."), "Blad", wxICON_ERROR);
                tempFile << line << '\n';
                file.close();
                tempFile.close();
                wxRemoveFile(tempFilePath);
                return;
            }
        } else if (currentAccountNumber == recipient) {
            destinationAccountFound = true;
            balance += amount;
            tempFile << currentAccountNumber << '\t' << name << '\t' << surname << '\t' << balance << '\n';
        } else {
            tempFile << currentAccountNumber << '\t' << name << '\t' << surname << '\t' << balance << '\n';
        }
    }
    file.close();
    tempFile.close();
    if (sourceAccountFound && destinationAccountFound && wxRenameFile(tempFilePath, filePath, true)) {
        wxMessageBox(_("Transakcja zakończona pomyślnie."), wxMessageBoxCaptionStr, wxICON_INFORMATION);
        globalComboBoxItems.erase(std::find(globalComboBoxItems.begin(), globalComboBoxItems.end(), wxString::Format("%d", num)));
        globalComboBoxItems.insert(globalComboBoxItems.begin(), wxString::Format("%d", num));
        globalComboBoxItems.erase(std::find(globalComboBoxItems.begin(), globalComboBoxItems.end(), wxString::Format("%d", recipient)));
        globalComboBoxItems.insert(globalComboBoxItems.begin(), wxString::Format("%d", recipient));
        Close(true);
    } else {
        wxMessageBox(_("Błąd podczas wykonywania transakcji."), "Blad", wxICON_ERROR);
        wxRemoveFile(tempFilePath);
    }
}
