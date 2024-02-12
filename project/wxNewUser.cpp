#include "wxNewUser.h"
#include "packages.h"

vector<wxString> globalComboBoxItems;

//(*InternalHeaders(wxNewUser)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(wxNewUser)
const long wxNewUser::ID_STATICTEXT1 = wxNewId();
const long wxNewUser::ID_TEXTCTRL1 = wxNewId();
const long wxNewUser::ID_STATICTEXT2 = wxNewId();
const long wxNewUser::ID_TEXTCTRL2 = wxNewId();
const long wxNewUser::ID_STATICTEXT3 = wxNewId();
const long wxNewUser::ID_TEXTCTRL3 = wxNewId();
const long wxNewUser::ID_STATICTEXT4 = wxNewId();
const long wxNewUser::ID_SPINCTRLDOUBLE1 = wxNewId();
const long wxNewUser::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxNewUser,wxDialog)
	//(*EventTable(wxNewUser)
	//*)
END_EVENT_TABLE()

wxNewUser::wxNewUser(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(wxNewUser)
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Dodaj nowego użytkownika"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(5, 2, 5, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Nr konta"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(230,35), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer1->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Imię"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(230,35), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	FlexGridSizer1->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Nazwisko"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(230,35), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	FlexGridSizer1->Add(TextCtrl3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Saldo konta"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SpinCtrlDouble1 = new wxSpinCtrlDouble(this, ID_SPINCTRLDOUBLE1, _T("0"), wxDefaultPosition, wxSize(230,35), 0, 0, 1e+09, 0, 0.01, _T("ID_SPINCTRLDOUBLE1"));
	SpinCtrlDouble1->SetValue(_T("0"));
	FlexGridSizer1->Add(SpinCtrlDouble1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("DODAJ UŻYTKOWNIKA"), wxDefaultPosition, wxSize(200,35), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxNewUser::create_account);
	//*)
	SetIcon(wxICON(aaaa));
}

wxNewUser::~wxNewUser()
{
	//(*Destroy(wxNewUser)
	//*)
}

std::string w2s(const wxString & w){
    return std::string(w.mb_str(wxConvUTF8));
}

bool isAccountNumberExists(int accountNumber)
{
    ifstream file("db.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            int currentAccountNumber;
            iss >> currentAccountNumber;
            if (currentAccountNumber == accountNumber) {
                file.close();
                return true;
            }
        }
        file.close();
    }
    return false;
}

void wxNewUser::create_account(wxCommandEvent& event)
{
    if (TextCtrl1->IsEmpty() || TextCtrl2->IsEmpty() || TextCtrl3->IsEmpty()) {
        wxMessageBox("Pole jest puste.", "Blad", wxICON_ERROR);
        return;
    } else if (!TextCtrl1->GetValue().IsNumber()) {
        wxMessageBox("Pole numer moze zawierac tylko liczby.", "Blad", wxICON_ERROR);
        return;
    }
    int number = stoi(w2s(TextCtrl1->GetValue()));
    string name = w2s(TextCtrl2->GetValue());
    string surname = w2s(TextCtrl3->GetValue());
    double balance = SpinCtrlDouble1->GetValue();
    if (isAccountNumberExists(number)) {
        wxMessageBox(_("Numer konta już istnieje!"), "Blad", wxICON_ERROR);
        return;
    }
    ofstream MyFile;
    MyFile.open("db.txt", ios_base::app);
    MyFile << number << "\t" << name << "\t" << surname << "\t" << balance << "\n";
    MyFile.close();
    wxMessageBox(_("Konto utworzone pomyślnie!"), wxMessageBoxCaptionStr, wxICON_INFORMATION);
    globalComboBoxItems.insert(globalComboBoxItems.begin(), wxString::Format("%d", number));
    Close(true);
}
