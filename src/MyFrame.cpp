#include "MyFrame.h"
#include <wx/tglbtn.h>

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame( NULL, -1, title, pos, size )
{
    wxMenuBar *menuBar = new wxMenuBar;
    wxMenu *menuFile = new wxMenu;
    menuFile->Append( ID_About, _("&About...") );
    menuBar->Append(menuFile, _("&Help") );
    SetMenuBar(menuBar);
    
    wxPanel *panel = new wxPanel(this, -1);
  
    wxToggleButton *tgb1 = new wxToggleButton(panel,-1, _("Left Channel"));
    wxToggleButton *tgb2 = new wxToggleButton(panel,-1, _("Right Channel"));
 
    wxFlexGridSizer *fgs = new wxFlexGridSizer(6,2,5,10);
    fgs->Add(tgb1,1,wxEXPAND);
    fgs->Add(tgb2,1,wxEXPAND);

    fgs->AddGrowableCol(0,1);
    fgs->AddGrowableCol(1,1);
    
    wxStaticBoxSizer *sbs = new wxStaticBoxSizer(wxVERTICAL,panel, _("Amplitude"));
    sbs->Add(fgs, 1, wxALL | wxEXPAND, 10);

    wxBoxSizer *bs = new wxBoxSizer(wxVERTICAL);
    bs->Add(sbs,1,wxALL | wxEXPAND, 25);
    panel->SetSizer(bs);
    Center();
        
}

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox( _("wxWidgets Hello World example."), 
                  _("About Hello World"),
                  wxOK|wxICON_INFORMATION, this );
}
