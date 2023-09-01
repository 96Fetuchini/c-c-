#include"Column.h"

class Compositor{
    public:
        //when to format
        virtual void Compose(){};
        //what to format
        void SetComposition(){};
};

class ArrayCompositor: public Compositor{
    public:
        void Compose(){}
};
class TeXCompositor: public Compositor{
    public:
        void Compose(){}
};
class SimpleCompositor: public Compositor{
    public:
        void Compose(){}
};

class Composition : public Glyph{
    /*Here we make the line breaking algorithm*/
    protected:
        Compositor format;
    public:
        Composition(){
            child = NULL;
            parent = NULL;
        }
        Composition(Glyph* c, Glyph* p){
            this->pos = wxPoint(0,0);
            child = c;
            parent = p;
        }
        void Draw(Window* w, const wxPoint& pos0){
            int width = w->getSize().x;
            child->Draw(w, pos0);
        }
        void Bounds(wxRect& r){}
        //hit detection
        bool Intersects(const wxPoint& p){
            return true;
        }
        //structure 
        void Insert(Glyph* g, const wxPoint& pos0){
            if(child == NULL)
                child = new Column(wxPoint(0,0), this);
            child->Insert(g, this->pos);
        }
        void Remove(Glyph* g){}
        void setChild(Glyph* g){
            this->child = g;
        }
        Glyph* Child(){
            return child;
        }
        Glyph* Parent(){
            return parent;
        }
};