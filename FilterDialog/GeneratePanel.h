#ifndef GENERATEPANEL_H
#define GENERATEPANEL_H

//(*Headers(FilterDialog)
#include <wx/button.h>
#include <wx/checklst.h>
#include <wx/dialog.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <map>
//*)


class GeneratePanel : public wxPanel
{
public:
	wxCheckListBox* CheckListBox1;
	GeneratePanel(wxWindow *parent, int ID);

	std::map<std::string, boolean> originalData;
	void loadData(std::map<std::string, boolean> output);

private:

	void OnButton2Click(wxCommandEvent& event);
	void OnButton3Click(wxCommandEvent& event);
	void OnTextCtrl1Text1(wxCommandEvent& event);
	void OnCheckListBox1Check(wxCommandEvent& event);
	//*)

	//(*Identifiers(FilterDialog)

	static const long ID_STATICTEXT1;
	static const long ID_TEXTCTRL1;
	static const long ID_CHECKLISTBOX1;
	static const long ID_BUTTON2;
	static const long ID_BUTTON3;
	static const long ID_PANEL;

	//*)

	//(*Declarations(FilterDialog)
	wxBoxSizer* BoxSizer1;
	wxButton* Button2;
	wxButton* Button3;
	wxStaticText* StaticText1;
	wxTextCtrl* TextCtrl1;
	//*)
};

#endif