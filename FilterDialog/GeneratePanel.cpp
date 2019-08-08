#include "GeneratePanel.h"

const long GeneratePanel::ID_STATICTEXT1 = wxNewId();
const long GeneratePanel::ID_TEXTCTRL1 = wxNewId();
const long GeneratePanel::ID_CHECKLISTBOX1 = wxNewId();
const long GeneratePanel::ID_BUTTON2 = wxNewId();
const long GeneratePanel::ID_BUTTON3 = wxNewId();
const long GeneratePanel::ID_PANEL = wxNewId();

GeneratePanel::GeneratePanel(wxWindow *parent, int winid) 
	: wxPanel(parent, winid, wxDefaultPosition, wxDefaultSize)
{
	wxPanel* Panel = new wxPanel(this, winid);

	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxFlexGridSizer* FlexGridSizer1;

	FlexGridSizer1 = new wxFlexGridSizer(2, 2, 0, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(Panel, ID_STATICTEXT1, _("Search:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer2->Add(StaticText1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl1 = new wxTextCtrl(Panel, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer2->Add(TextCtrl1, 2, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(BoxSizer2, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(-1, -1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
	CheckListBox1 = new wxCheckListBox(Panel, ID_CHECKLISTBOX1, wxDefaultPosition, wxSize(100,220), 0, 0, 0, wxDefaultValidator, _T("ID_CHECKLISTBOX1"));
	FlexGridSizer1->Add(CheckListBox1, 1, wxALL | wxEXPAND, 5);
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	Button2 = new wxButton(Panel, ID_BUTTON2, _("Clear"), wxDefaultPosition, wxSize(125, 22), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer3->Add(Button2, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(-1, -1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
	Button3 = new wxButton(Panel, ID_BUTTON3, _("Apply"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer3->Add(Button3, 1, wxALL | wxEXPAND, 5);	
	FlexGridSizer1->Add(BoxSizer3, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
	Panel->SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(Panel);
	FlexGridSizer1->SetSizeHints(Panel);

	Connect(ID_TEXTCTRL1, wxEVT_COMMAND_TEXT_UPDATED, (wxObjectEventFunction)&GeneratePanel::OnTextCtrl1Text1);
	Connect(ID_CHECKLISTBOX1, wxEVT_CHECKLISTBOX, (wxObjectEventFunction)&GeneratePanel::OnCheckListBox1Check);
	Connect(ID_BUTTON2, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&GeneratePanel::OnButton2Click);
	Connect(ID_BUTTON3, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&GeneratePanel::OnButton3Click);
	
	//Original Dummy Information
	originalData["Billy"] = true;
	originalData["Bob"] = true;
	originalData["Terry"] = false;
	originalData["Berry"] = true;
	loadData(originalData);
}

void GeneratePanel::OnButton2Click(wxCommandEvent& event)
{
	//Clear
	for (std::map<std::string, boolean>::iterator it = originalData.begin();it != originalData.end();it++) {
		originalData[it->first] = false;
	}

	loadData(originalData);
	TextCtrl1->Clear();
}

void GeneratePanel::OnButton3Click(wxCommandEvent& event)
{
	//Apply
	Close();
}

void GeneratePanel::OnTextCtrl1Text1(wxCommandEvent& event)
{	
	//Search
	std::map<std::string, boolean> filter;

	if (TextCtrl1->IsEmpty() == true) {
		filter = originalData;
	}
	else {
		wxString search = TextCtrl1->GetValue();
		for (std::map<std::string, boolean>::iterator it = originalData.begin();it != originalData.end();it++) {
			wxString data = (it->first);
			if ((data.Lower()).Contains(search.Lower())) {
				
				filter[it->first] = it->second;
			}
		}
	}

	loadData(filter);
}

void GeneratePanel::OnCheckListBox1Check(wxCommandEvent& event)
{
	int index = 0;
	for (std::map<std::string, boolean>::iterator it = originalData.begin();it != originalData.end();it++) {
		originalData[it->first] = CheckListBox1->IsChecked(index);
		index++;
	}

	loadData(originalData);
}

void GeneratePanel::loadData(std::map<std::string, boolean> output)
{
	CheckListBox1->Clear();

	int index = 0;
	for (std::map<std::string, boolean>::iterator it = output.begin();it != output.end();it++) {
		CheckListBox1->Append(it->first);
		if (it->second == true) {
			CheckListBox1->Check(index, true);
		}
		index++;
	}
}