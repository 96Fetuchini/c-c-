#include "Window.h"
#include "DataStructures/LinkedList.h"
class Glyph{
    public:
        //Appearance
        virtual void Draw(Window*) = 0;
        virtual void Bounds(wxRect&) = 0;
        //hit detection
        virtual bool Intersects(const wxPoint&) = 0;
        //structure 
        virtual void Insert(Glyph*, int) = 0;
        virtual void Remove(Glyph*) = 0;
        virtual Glyph* Child(int) = 0;
        virtual Glyph* Parent() = 0;
};

class Character: public Glyph{
    private:
        char c;
        wxPoint pos;
        wxRect bounds;
        wxFont font;
        Glyph* parent;//a character is always a leaf in the document tree
        /*
        We should consider that the size has 
        to be given in order to determine bounds
        and send it to the windowimplementation
        for rendering
        */
    public:
        Character(const char& c,const wxPoint &pos, Glyph* parent){
            this->c = c;
            this->pos = pos;
            this->bounds = wxRect(pos, pos);
            this->parent = parent;
            this->font = wxFont();
            /*
            int px = pt * 4 / 3;
            wxSize fontSize = wxSize(px * 2 / 5, px);
            wxFont(wxSize(2 , 5), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
            */
            
            /*
            wxPanel p;
            wxClientDC dc(&p);
            wxSize size = dc.GetTextExtent(wxString(c));
            bounds = wxRect(
                pos, wxPoint(pos.x + size.GetWidth(), pos.y + size.GetWidth())
            );*/
        }
        void SetPosition(const wxPoint &pos){
            this->pos = pos;
        }
        void Draw(Window* w){
            w->DrawText(c, pos, this->font);
        }
        void SetFont(const wxFont &font){
            this->font = font;
            bounds = wxRect(
                wxPoint(pos.x, pos.y),
                wxPoint(pos.x + font.GetPixelSize().x , pos.y + font.GetPixelSize().y)
            );
        }
        void Draw(Window* w, const wxFont &font){
            SetFont(font);
            w->DrawText(c, pos, this->font);
        }
        void Bounds(wxRect& b){
            b = this->bounds;
        }
        //hit detection
        bool Intersects(const wxPoint& p){
            int dx0 = bounds.GetTopRight().x - bounds.GetTopLeft().x;
            int dy0 = bounds.GetBottomRight().y - bounds.GetTopRight().y;
            int dx1 = p.x - bounds.GetTopLeft().x;
            int dy1 = p.y - bounds.GetTopLeft().y;
            if(dx1 <= dx0 && dy1 <= dy0)
                return true;
            return false;
        }       
        //structure 
        void Insert(Glyph*, int){}
        void Remove(Glyph*){}
        Glyph* Child(int){
            return NULL;
        }
        Glyph* Parent(){
            return parent;
        }
};

class Row: public Glyph{
    private:
        Glyph* parent;
        LinkedList<Glyph*> simbols;
    public:
        void Draw(Window*){}
        void Bounds(wxRect&){}
        //hit detection
        bool Intersects(const wxPoint&){
            return true;
        }
        //structure 
        void Insert(Glyph* g, int){}
        void Remove(Glyph*){}
        Glyph* Child(int){
            return NULL;
        }
        Glyph* Parent(){
            return NULL;
        }
};
class Column: public Glyph{
    private:
        Glyph* parent;
        LinkedList<Glyph*> rows;
    public:
        void Draw(Window*){}
        void Bounds(wxRect&){}
        //hit detection
        bool Intersects(const wxPoint&){
            return true;
        }
        //structure 
        void Insert(Glyph* g, int){}
        void Remove(Glyph*){}
        Glyph* Child(int){
            return NULL;
        }
        Glyph* Parent(){
            return NULL;
        }
};