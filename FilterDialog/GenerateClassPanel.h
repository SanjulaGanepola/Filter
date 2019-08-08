#ifndef GENERATECLASSPANEL_H
#define GENERATECLASSPANEL_H

//(*Headers(FilterDialog)
#include <wx/button.h>
#include <wx/checklst.h>
#include <wx/dialog.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/treelist.h>
//*)


class GenerateClassPanel : public wxPanel
{
public:
	GenerateClassPanel(wxWindow *parent, int ID);
	void loadData();

private:

	void OnButton2Click(wxCommandEvent& event);
	void OnButton3Click(wxCommandEvent& event);
	//*)

	//(*Identifiers(FilterDialog)

	static const long ID_BUTTON2;
	static const long ID_BUTTON3;
	static const long ID_PANEL;
	static const long ID_TREELISTCTRL1;

	//*)

	//(*Declarations(FilterDialog)
	wxBoxSizer* BoxSizer1;
	wxButton* Button2;
	wxButton* Button3;
	wxStaticText* StaticText1;
	wxTextCtrl* TextCtrl1;
	wxTreeListCtrl* TreeListCtrl1;
	//*)
};

#endif