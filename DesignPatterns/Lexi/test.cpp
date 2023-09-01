#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include<iostream>
class panel2: public wxPanel{
    private:

    public:
        panel2(wxPanel* panel): wxPanel(panel, wxID_ANY){
            Bind(wxEVT_KEY_DOWN, &Char, this);
        }
        void mouseWheel(wxMouseEvent& event){
            std::cout <<  "MouseWheel" <<std::endl;
            wxPostEvent(GetParent(), event);
        }
        void Char(wxKeyEvent& event){
            std::cout <<  "Char Panel2" <<std::endl;
            wxPostEvent(GetParent(), event);
            /*
            std::cout<< "char" << std::endl;
            std::cout<< event.GetUnicodeKey() << std::endl;
            std::cout<< char(event.GetUnicodeKey()) << std::endl;
            */
        }
};

class Panel: public wxPanel{
    private:
        panel2 *hvsw;
    public:
        Panel(wxFrame* frame): wxPanel(frame, wxID_ANY){
            hvsw = new panel2(this);
            Bind(wxEVT_MOTION, &mouse, this);
            SetFocus();
        }
        void Char(wxKeyEvent& event){
            std::cout <<  "Char Panel" <<std::endl;
            wxPostEvent(GetParent(), event);
            /*
            std::cout<< "char" << std::endl;
            std::cout<< event.GetUnicodeKey() << std::endl;
            std::cout<< char(event.GetUnicodeKey()) << std::endl;
            */
        }
        void mouse(wxMouseEvent& event){
            std::cout <<  "Mouse Panel" <<std::endl;
            wxPostEvent(GetParent(), event);
            /*
            std::cout <<  "Mouse" <<std::endl;
            std::cout <<  event.GetPosition().x <<std::endl;
            std::cout <<  event.GetPosition().y <<std::endl;
            */
        }
};

class Frame: public wxFrame{
    private:
        Panel* panel;
    public:
        Frame(const wxString name):wxFrame(NULL, wxID_ANY, name){
            panel = new Panel(this);
            Bind(wxEVT_CHAR, &Char, this);
            Bind(wxEVT_MOTION, &mouse, this);
            SetFocus();
        }
        void Char(wxKeyEvent& event){
            std::cout<< char(event.GetUnicodeKey()) << std::endl;
        }
        void mouse(wxMouseEvent& event){
            std::cout << event.GetPosition().x <<std::endl;
            std::cout << event.GetPosition().y <<std::endl;
        }
};

class MyApp: public wxApp{
    private:
        Frame *f;
        //MyFrame *frame;
    public:
        bool OnInit(){
            f = new Frame("Test");
            f->Show(true);
            return true;
        }
        //EVENTS
        
};

wxIMPLEMENT_APP(MyApp);