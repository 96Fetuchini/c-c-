#ifndef WINDOWDEF
#define WINDOWDEF

#include"WindowImp.h"

class Window{
    protected:
        WindowsWindowImp *w;
    public:
        Window(const wxString &title, const wxSize &size){
            w = new WindowsWindowImp(title, size);
        }
        void Show(bool b){
            w->Show(b);
        }
        wxRect getSize(){
            return w->GetClientRect();
        }
        ActionEvent GetActionEvent(){
            return w->GetActionEvent();
        }
        wxSize getMinSize(){
            return w->GetMinSize();
        }
        wxSize getMaxSize(){
            return w->GetMaxSize();
        }
        wxKeyEvent& getKeyEvent(){
            return w->getKeyEvent();
        }
        void CloseWindow(bool c){
            w->Close(true);
        }
        bool IsQuited(){
            return w->IsQuited();
        }
        bool isKeyEvent(){
            return w->isKeyEvent();
        }
        //re-renders window
        virtual void Render(){
            w->render();
        }
        virtual void ReDraw(){
            w->ReDraw();
        };
        //opens a document
        virtual void Open(){};
        //closes a document
        virtual void Close(){};
        //convert window in an icon
        virtual void Iconify(){};
        //reverse convertion of an icon to a window
        virtual void Deiconify(){};
        //virtual void SetOrigin(const wxPoint& at);
        //virtual void SetExtent(const wxPoint& extent);
        //scroll motion up
        virtual void Raise(){};
        //scroll motion down
        virtual void Lower(){};
        virtual void DrawLine(const wxPoint&, const wxPoint&){};
        virtual void DrawRect(const wxPoint&, const wxPoint&){};
        virtual void DrawPolygon(const wxPoint [], const wxPoint&){};
        virtual void DrawText(const char&, const wxPoint&, const wxFont&){};
};

//main window for the application
class ApplicationWindow: public Window{
    protected:
        //Menu *menu;
    public:
        ApplicationWindow(const wxString &title, const wxSize &size): Window(title, size){
            
        }
        void ReDraw(){
            w->ReDraw();
        }
        void Open(){}
        void Close(){}
        void Iconify(){
            w->Show(false);
        }
        void Deiconify(){
            w->Show(true); 
        }
        //Menu
        /*
        void AddToMenu(MenuItem *mi){
            menu->add(mi);
        }
        */
        //void SetOrigin(const wxPoint& at);
        //void SetExtent(const wxPoint& extent);
        void Raise(){}
        void Lower(){}
        void DrawLine(const wxPoint& p0, const wxPoint& p1){
            w->DeviceLine(p0, p1);
        }
        void DrawRect(const wxPoint &p0, const wxPoint &p1){
            w->DeviceRect(p0, p1);
        }
        void DrawPolygon(const wxPoint [], const wxPoint&){}
        void DrawText(const char &c, const wxPoint &p, const wxFont &font){
            w->DeviceText(c, p, font);
        }
        wxSize getCharSize(const char &c, const wxFont &font){
            return w->getCharSize(c, font);
        }
};
//complementary window for putting glyph icons
class IconWindow: public Window{

};
//complementary window for showing messages
class DialogWindow: public Window{

};

#endif
