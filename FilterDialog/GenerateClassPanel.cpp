#include "GenerateClassPanel.h"

const long GenerateClassPanel::ID_TREELISTCTRL1 = wxNewId();
const long GenerateClassPanel::ID_BUTTON2 = wxNewId();
const long GenerateClassPanel::ID_BUTTON3 = wxNewId();
const long GenerateClassPanel::ID_PANEL = wxNewId();

GenerateClassPanel::GenerateClassPanel(wxWindow *parent, int winid
) : wxPanel(parent, winid, wxDefaultPosition, wxDefaultSize)
{
	wxPanel* Panel = new wxPanel(this, winid);
	wxBoxSizer* BoxSizer3;
	wxFlexGridSizer* FlexGridSizer1;

	FlexGridSizer1 = new wxFlexGridSizer(1, 2, 0, 0);
	TreeListCtrl1 = new wxTreeListCtrl(Panel, ID_TREELISTCTRL1, wxDefaultPosition, wxSize(180, 270), wxTL_DEFAULT_STYLE, _T("ID_TREELISTCTRL1"));
	TreeListCtrl1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	FlexGridSizer1->Add(TreeListCtrl1, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
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

	Connect(ID_BUTTON2, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&GenerateClassPanel::OnButton2Click);
	Connect(ID_BUTTON3, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&GenerateClassPanel::OnButton3Click);
}

void GenerateClassPanel::OnButton2Click(wxCommandEvent& event)
{
	//Clear
}

void GenerateClassPanel::OnButton3Click(wxCommandEvent& event)
{
	//Apply
	Close();
}

void GenerateClassPanel::loadData()
{
	//Loading Data
}