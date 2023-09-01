#include "DataStructures/LinkedList.h"

#include "Window.h"

class Glyph{
    public:
        wxPoint pos;//Glyph positions are relative
        wxRect bounds;
        Glyph* parent;
        Glyph* child;
        //Appearance
        virtual void Draw(Window*, const wxPoint&) = 0;
        virtual void Bounds(wxRect&) = 0;
        //hit detection
        virtual bool Intersects(const wxPoint&) = 0;
        //structure 
        virtual void Insert(Glyph*, const wxPoint&) = 0;
        virtual void Remove(Glyph*) = 0;
        virtual Glyph* Child() = 0;
        virtual Glyph* Parent() = 0;
};

