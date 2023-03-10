#include"WindowImp.h"
#include<iostream>

class Window{
    protected:
        WindowsWindowImp *w;
    public:
        Window(const wxString &title){
            w = new WindowsWindowImp(title);
        }
        void Show(bool b){
            w->Show(b);
        }
        //re-renders window
        virtual void ReDraw(){};
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
    public:
        ApplicationWindow(const wxString &title): Window(title){}
        void ReDraw(){
            w->Refresh();
        }
        void Open(){}
        void Close(){}
        void Iconify(){}
        void Deiconify(){}

        //void SetOrigin(const wxPoint& at);
        //void SetExtent(const wxPoint& extent);
        void Raise(){}
        void Lower(){}
        void DrawLine(const wxPoint&, const wxPoint&){}
        void DrawRect(const wxPoint &p0, const wxPoint &p1){
            w->DeviceRect(p0, p1);
        }
        void DrawPolygon(const wxPoint [], const wxPoint&){}
        void DrawText(const char &c, const wxPoint &p, const wxFont &font){
            w->DeviceText(c, p, font);
        }
};
//complementary window for putting glyph icons
class IconWindow: public Window{

};
//complementary window for showing messages
class DialogWindow: public Window{

};