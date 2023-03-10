// wxWidgets "Hello World" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include "Glyph.h"
#include<iostream>
class MyApp : public wxApp{
    private:
        Character** c;
        wxFont font;
        ApplicationWindow *w;
    public:
        virtual bool OnInit(){ 
            c = new Character*[2];
            w = new ApplicationWindow("Lexi");
            int pt = 12;
            int px = (pt) * 4 / 3;
            wxSize fontSize = wxSize(px * 2 / 5, px);
            font = wxFont(fontSize, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
            std::cout << "psize = (" << font.GetPixelSize().x << "," << font.GetPixelSize().y << ")" <<std::endl;
            w->Show(true);
            c[0] = new Character('a', wxPoint(0,0), NULL);
            c[1] = new Character('b', wxPoint(0,16), NULL);
            c[0]->Draw(w, font);
            c[1]->Draw(w, font);
            std::cout << c[0]->Intersects(wxPoint(0,0)) << std::endl;
            std::cout << c[0]->Intersects(wxPoint(3,14)) << std::endl;
            return true;
        }
};

wxIMPLEMENT_APP(MyApp);