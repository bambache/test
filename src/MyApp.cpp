#include "MyApp.h"
#include "MyFrame.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame( _("Hello World"), wxPoint(50, 50),
                                  wxSize(450, 350));

    frame->Connect( ID_About, wxEVT_COMMAND_MENU_SELECTED,
                    (wxObjectEventFunction) &MyFrame::OnAbout );

    frame->Show(true);
    SetTopWindow(frame);
    return true;
}
