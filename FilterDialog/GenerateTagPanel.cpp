#include "GenerateTagPanel.h"

const long GenerateTagPanel::ID_LISTCTRL1 = wxNewId();
const long GenerateTagPanel::ID_BUTTON2 = wxNewId();
const long GenerateTagPanel::ID_BUTTON3 = wxNewId();
const long GenerateTagPanel::ID_PANEL = wxNewId();

GenerateTagPanel::GenerateTagPanel(wxWindow *parent, int winid
) : wxPanel(parent, winid, wxDefaultPosition, wxDefaultSize)
{
	wxPanel* Panel = new wxPanel(this, winid);

	//wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxFlexGridSizer* FlexGridSizer1;

	FlexGridSizer1 = new wxFlexGridSizer(2, 1, 0, 0);
	
	ListCtrl1 = new wxListCtrl(this, ID_LISTCTRL1, wxDefaultPosition, wxSize(320,220), wxLC_REPORT);
	// Add first column       
	wxListItem col0;
	col0.SetId(0);
	col0.SetText(_("Header 1"));
	col0.SetWidth(160);
	ListCtrl1->InsertColumn(0, col0);

	// Add second column
	wxListItem col1;
	col1.SetId(1);
	col1.SetText(_("Header 2"));
	col1.SetWidth(160);
	ListCtrl1->InsertColumn(1, col1);

	FlexGridSizer1->Add(ListCtrl1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	Button2 = new wxButton(Panel, ID_BUTTON2, _("Clear"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer3->Add(Button2, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
	Button3 = new wxButton(Panel, ID_BUTTON3, _("Apply"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer3->Add(Button3, 1, wxALL | wxEXPAND, 5);
	FlexGridSizer1->Add(BoxSizer3, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
	Panel->SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(Panel);
	FlexGridSizer1->SetSizeHints(Panel);

	Connect(ID_BUTTON2, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&GenerateTagPanel::OnButton2Click);
	Connect(ID_BUTTON3, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&GenerateTagPanel::OnButton3Click);

	//Original Dummy Information
	originalData["Billy"] = "1";
	originalData["Bob"] = "2";
	originalData["Terry"] = "3";
	originalData["Cerry"] = "4";
	loadData(originalData);
}

void GenerateTagPanel::OnButton2Click(wxCommandEvent& event)
{
	//Clear
	ListCtrl1->ClearAll();
}

void GenerateTagPanel::OnButton3Click(wxCommandEvent& event)
{
	//Apply
}

void GenerateTagPanel::loadData(std::map<std::string, std::string> output)
{
	//Loading Data
	int index = 0;
	for (std::map<std::string, std::string>::iterator it = output.begin();it != output.end();it++) {
		
		wxListItem item;
		item.SetId(index);

		ListCtrl1->InsertItem(item);

		//first column
		ListCtrl1->SetItem(index, 0, it->first);
		// second column
		ListCtrl1->SetItem(index, 1, it->second);
		index++;
	}
}