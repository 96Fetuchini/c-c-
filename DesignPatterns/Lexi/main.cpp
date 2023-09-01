//#include "Menu.h"
#include <wx/wxprec.h>
#include<iostream>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "Window.h"
#include "Compositor.h"

class MyApp : public wxApp{
    private:
        //LinkedList<Character*> str;
        wxFont font;
        wxSize fontSize;
        ApplicationWindow *w;
        ActionEvent Observer;
        Composition *comp;
        Character* inputKey;
        int keyCount;
        //Border *b;
    public:
        bool OnInit(){
            //comp = new Composition(NULL, b);
            //-b = new Border(comp, NULL);
            //LinkedListIterator<Character*> it;)
            w = new ApplicationWindow("Lexi", wxSize(400,400));
            w->Deiconify();
            w->Render();
            BindRenderLoop();
            comp = new Composition();
            keyCount = 0;

            int pt = 16;
            int px = (pt) * 4 / 3;
            fontSize = wxSize(px * 2 / 5, px);
            font = wxFont(fontSize, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
            /*
            wxString input = "aSiasdvawersedfhbvkjsehrbgkusehrngvksdjfnvksiurhjtnslkfvjbnwksireugnsldkfjnskrtjhgbajsdnfkvjwhertngkjasherngksjrhtbgksdjhfv";
            Character* c = NULL;
            c = new Character('a', NULL, wxPoint(0, 0), wxRect(0, 0, fontSize.x, fontSize.y), font);
            for(int i = 0; i < input.size(); i++){
                fontSize = w->getCharSize(input[i], font);
                c = new Character(input[i], NULL, wxPoint(0, 0), wxRect(0, 0, fontSize.x, fontSize.y), font);
                str.insert(c);
                c = NULL;
            }  
            it = LinkedListIterator<Character*>(str.getFirst());
            for(int i = 0; i < str.getSize(); i++){
                b->Insert(*SSit, i);
                ++it;
            }
            b->Draw(w, wxPoint(0,0));
            w->render();
            */
            return true;
        } 
        void BindRenderLoop(){
            Bind(wxEVT_IDLE, wxIdleEventHandler(MyApp::OnIdle), this);
        } 
        void UnBindRenderLoop(){
            Unbind(wxEVT_IDLE, wxIdleEventHandler(MyApp::OnIdle), this);
        }
        void OnIdle(wxIdleEvent& event){
            /*This is the loop*/
            if(w->IsQuited()){
                UnBindRenderLoop();
            }
            //The program goes here
            if(w->isKeyEvent()){
                if(inputKey != NULL)
                    inputKey = NULL;
                fontSize = w->getCharSize(w->getKeyEvent().GetUnicodeKey(), font);
                inputKey = new Character(
                    w->getKeyEvent().GetUnicodeKey(), 
                    NULL, 
                    wxPoint(0, 0), 
                    wxRect(0, 0, fontSize.x, fontSize.y),
                    font
                );
                comp->Insert(inputKey, wxPoint(0, 0));
                //std::cout << "KeyCount = " << keyCount << std::endl;
                comp->Draw(w, wxPoint(10,10));
                w->ReDraw();
            }
            if(Observer.isMouseEvent()){
                
            }
        }
        /*
        int OnRun(){
            return 0;
        }
        */
        int OnExit(){
            std::cout<< "Exit" << std::endl;
            return 0;
        }
};

wxIMPLEMENT_APP(MyApp);
