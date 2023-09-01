#include "Window.h"
#include "Compositor.h"

class MonoGlyph: public Glyph{
    public:
        MonoGlyph(){}
        MonoGlyph(Glyph* c, Glyph* p){
            this->child = c;
            this->parent = p;
        }
        virtual void Draw(Window* w, const wxPoint& p){
            child->Draw(w, p);
        }
        void Bounds(wxRect& r){}
        //hit detection
        bool Intersects(const wxPoint& p){
            return true;
        }
        //structure 
        void Insert(Glyph* g, int i){
            child->Insert(g, i);
        }
        void Remove(Glyph*){}
        Glyph* Child(){
            return NULL;
        }
        Glyph* Parent(){    
            return NULL;
        }
};


class Border: public MonoGlyph{
    public:
        Border(){}
        Border(Glyph* c, Glyph* p):MonoGlyph(c, p){}
        void Draw(Window *w, const wxPoint& p){
            MonoGlyph::Draw(w, wxPoint(0,0));
            DrawBorder(w, p);
        }
        void DrawBorder(Window *w, const wxPoint& p){
            w->DrawLine(
                wxPoint(0,0), 
                wxPoint(0, w->getSize().y)
            );
            w->DrawLine(
                wxPoint(w->getSize().x, 0), 
                wxPoint(0, 200)
            );
        }
};

class Scroller: public MonoGlyph{
    public:
        Scroller(){}
        Scroller(Glyph* c, Glyph* p):MonoGlyph(c, p){}
        void Draw(Window *w, const wxPoint& p){
            MonoGlyph::Draw(w, wxPoint(0,0));
        }
        void DrawScroller(Window *w, const wxPoint& p){
            
        }
};