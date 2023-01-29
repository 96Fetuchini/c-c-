// wxWidgets "Hello World" Program
 
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <wx/vscroll.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class MyApp : public wxApp{
    public:
        virtual bool OnInit();
};

enum{
    ID_Hello = 1,
    ID_MYFRAME = 2
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    wxFrame *frame = new wxFrame(NULL, ID_MYFRAME, argv[0]);
    frame->Show(true);
    frame->SetScrollbar(wxVERTICAL, 0, 20, 50);
    return true;
}



