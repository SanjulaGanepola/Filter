/***************************************************************
 * Name:      FilterMain.h
 * Purpose:   Defines Application Frame
 * Author:    Sanjula ()
 * Created:   2019-06-11
 * Copyright: Sanjula ()
 * License:
 **************************************************************/

#ifndef FILTERMAIN_H
#define FILTERMAIN_H

 //(*Headers(FilterDialog)
#include <wx/button.h>
#include <wx/checklst.h>
#include <wx/dialog.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>

//*)

class FilterDialog : public wxDialog
{
public:

	FilterDialog(wxWindow* parent, wxWindowID id = -1);

private:


	//(*Identifiers(FilterDialog)
	static const long ID_STATICTEXT1;
	static const long ID_TEXTCTRL1;
	static const long ID_CHECKLISTBOX1;
	static const long ID_BUTTON1;
	static const long ID_BUTTON2;
	static const long ID_BUTTON3;
	static const long ID_USERS_PANEL;
	static const long ID_ALGORITHMS_PANEL1;
	static const long ID_CLASSES_PANEL;
	static const long ID_TAG_PANEL;
	static const long ID_ID_PANEL;
	static const long ID_NOTEBOOK1;
	//*)

	//(*Declarations(FilterDialog)
	wxBoxSizer* BoxSizer1;
	wxButton* Button1;
	wxButton* Button2;
	wxButton* Button3;
	wxCheckListBox* CheckListBox1;
	wxNotebook* Notebook1;
	wxPanel* AlgorithmsPanel;
	wxPanel* ClassesPanel;
	wxPanel* IDPanel;
	wxPanel* TagPanel;
	wxPanel* UsersPanel;
	wxStaticText* StaticText1;
	wxTextCtrl* TextCtrl1;
	//*)

	DECLARE_EVENT_TABLE()
};

#endif // FILTERMAIN_H
