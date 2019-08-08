/***************************************************************
 * Name:      FilterMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Sanjula ()
 * Created:   2019-06-11
 * Copyright: Sanjula ()
 * License:
 **************************************************************/

#include "FilterMain.h"
#include "GeneratePanel.h"
#include "GenerateClassPanel.h"
#include "GenerateTagPanel.h"
#include <wx/msgdlg.h>

 //(*InternalHeaders(FilterDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
	short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
	wxString wxbuild(wxVERSION_STRING);

	if (format == long_f)
	{
#if defined(__WXMSW__)
		wxbuild << _T("-Windows");
#elif defined(__UNIX__)
		wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
		wxbuild << _T("-Unicode build");
#else
		wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
	}

	return wxbuild;
}

//(*IdInit(FilterDialog)
const long FilterDialog::ID_STATICTEXT1 = wxNewId();
const long FilterDialog::ID_TEXTCTRL1 = wxNewId();
const long FilterDialog::ID_CHECKLISTBOX1 = wxNewId();
const long FilterDialog::ID_BUTTON1 = wxNewId();
const long FilterDialog::ID_BUTTON2 = wxNewId();
const long FilterDialog::ID_BUTTON3 = wxNewId();
const long FilterDialog::ID_USERS_PANEL = wxNewId();
const long FilterDialog::ID_ALGORITHMS_PANEL1 = wxNewId();
const long FilterDialog::ID_CLASSES_PANEL = wxNewId();
const long FilterDialog::ID_TAG_PANEL = wxNewId();
const long FilterDialog::ID_ID_PANEL = wxNewId();
const long FilterDialog::ID_NOTEBOOK1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(FilterDialog, wxDialog)
//(*EventTable(FilterDialog)
//*)
END_EVENT_TABLE()

FilterDialog::FilterDialog(wxWindow* parent, wxWindowID id)
{
	Create(parent, wxID_ANY, _("wxWidgets app"), wxDefaultPosition, wxSize(355, 360), wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxSize(355,360), 0, _T("ID_NOTEBOOK1"));
	Notebook1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));

	GeneratePanel* UserPanel = new GeneratePanel(Notebook1, wxID_ANY);
	GeneratePanel* AlgorithmsPanel = new GeneratePanel(Notebook1, wxID_ANY);
	GenerateClassPanel* ClassesPanel = new GenerateClassPanel(Notebook1, wxID_ANY);	
	GenerateTagPanel* TagPanel = new GenerateTagPanel(Notebook1, wxID_ANY);
	
	Notebook1->AddPage(UserPanel, _("Users"), false);
	Notebook1->AddPage(AlgorithmsPanel, _("Algorithms"), false);
	Notebook1->AddPage(ClassesPanel, _("Classes"), false);
	Notebook1->AddPage(TagPanel, _("Tag"), false);
}