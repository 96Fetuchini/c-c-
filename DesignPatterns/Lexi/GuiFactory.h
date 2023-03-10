#include"Window.h"

class GuiFactory{
    public:
        virtual wxScrollBar CreateScrollBar() = 0;
        virtual void CreateButton() = 0;
        virtual void CreateMenu() = 0;
};

class WindowGuiFactory: public GuiFactory{
    wxScrollBar CreateScrollBar(Window *w){
        
    }
    void CreateButton(){

    }
    void CreateMenu(){

    }
};