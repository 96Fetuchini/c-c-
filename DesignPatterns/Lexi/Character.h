#include"Glyph.h"

class Character: public Glyph{
    private:
        char c;
        wxFont font;
        /*
        We should consider that the size has 
        to be given in order to determine bounds
        and send it to the windowimplementation
        for rendering
        */
    public:
        Character(
                    const char& c, 
                    Glyph* parent, 
                    const wxPoint &pos = wxPoint(0, 0), 
                    wxRect bounds = wxRect(0,0,0,0), 
                    wxFont font = wxFont()
                )
        {
            this->c = c;
            this->pos = pos;
            this->bounds = bounds;
            this->parent = parent;
            this->child = NULL;
            this->font = font;
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
        void SetFont(const wxFont &font, const wxPoint& pos0 = wxPoint(0, 0)){
            this->font = font;
            bounds = wxRect(
                wxPoint(pos.x, pos.y) + pos0,
                wxPoint(pos.x + font.GetPixelSize().x , pos.y + font.GetPixelSize().y) + pos0
            );
        }
        void Draw(Window* w, const wxPoint& pos0 = wxPoint(0, 0)){
            //ojo con este if
            //if(w->getSize().x < pos0.x)
                //std::cout << pos0.x << std::endl;
                
            w->DrawText(c, pos + pos0, this->font);
        }
        char getCharacter(){
            return c;
        }
        //we have to review the formal parameters of this function
        //pos0 is the position of the parent container Glyph, pos serves as a relative position 
        //inside the parents bounds
        void Draw(Window* w, const wxFont &font, const wxPoint& pos0){
            SetFont(font);
            w->DrawText(c, pos + pos0, this->font);
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
        void Insert(Glyph* g, const wxPoint& pos0){
            this->pos = pos0;
            
        }
        void Remove(Glyph*){}
        Glyph* Child(){
            return NULL;
        }
        Glyph* Parent(){
            return parent;
        }
};