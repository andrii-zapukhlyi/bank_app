#include "wxUsun.h"
#include "packages.h"

extern string filePath;
extern string tempFilePath;
extern vector<wxString> globalComboBoxItems;


//(*InternalHeaders(wxUsun)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(wxUsun)
const long wxUsun::ID_STATICTEXT1 = wxNewId();
const long wxUsun::ID_COMBOBOX1 = wxNewId();
const long wxUsun::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxUsun,wxDialog)
	//(*EventTable(wxUsun)
	//*)
END_EVENT_TABLE()

wxUsun::wxUsun(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(wxUsun)
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, _("Usuń konto"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(2, 2, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Nr konta"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboBox1 = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxSize(230,35), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
	FlexGridSizer1->Add(ComboBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("POTWIERDŹ"), wxDefaultPosition, wxSize(175,35), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxUsun::delete_account);
	//*)
	SetIcon(wxICON(aaaa));
    for (const auto& item : globalComboBoxItems) {
        ComboBox1->Append(item);
    }
}

wxUsun::~wxUsun()
{
	//(*Destroy(wxUsun)
	//*)
}




void wxUsun::delete_account(wxCommandEvent& event)
{
    if (ComboBox1->wxItemContainerImmutable::IsEmpty()){
        wxMessageBox("Pole jest puste.", "Blad", wxICON_ERROR);
        return;
    } else if (!ComboBox1->GetValue().IsNumber()) {
        wxMessageBox("Pole numer moze zawierac tylko liczby.", "Blad", wxICON_ERROR);
        return;
    }
    int num = stoi(w2s(ComboBox1->GetValue()));
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
        } else {
            tempFile << currentAccountNumber << '\t' << name << '\t' << surname << '\t' << balance << '\n';
        }
    }
    file.close();
    tempFile.close();
    if (found && wxRenameFile(tempFilePath, filePath, true)) {
        wxMessageBox(_("Konto usunięte pomyślnie."), wxMessageBoxCaptionStr, wxICON_INFORMATION);
        globalComboBoxItems.erase(std::find(globalComboBoxItems.begin(), globalComboBoxItems.end(), wxString::Format("%d", num)));
        Close(true);
    } else {
        wxMessageBox(_("Nie znaleziono konta lub wystąpił błąd podczas usuwania konta."), "Blad", wxICON_ERROR);
        wxRemoveFile(tempFilePath);
    }
}
