#ifndef GENERATETAGPANEL_H
#define GENERATETAGPANELH

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
#include <wx/listctrl.h>
#include <map>
//*)


class GenerateTagPanel : public wxPanel
{
public:
	GenerateTagPanel(wxWindow *parent, int ID);

	std::map<std::string, std::string> originalData;	
	void loadData(std::map<std::string, std::string> output);

private:

	void OnButton2Click(wxCommandEvent& event);
	void OnButton3Click(wxCommandEvent& event);
	//*)

	//(*Identifiers(FilterDialog)

	static const long ID_BUTTON2;
	static const long ID_BUTTON3;
	static const long ID_PANEL;
	static const long ID_LISTCTRL1;

	//*)

	//(*Declarations(FilterDialog)
	wxBoxSizer* BoxSizer1;
	wxButton* Button2;
	wxButton* Button3;
	wxStaticText* StaticText1;
	wxTextCtrl* TextCtrl1;
	wxListCtrl* ListCtrl1;
	//*)
};

#endif