#include "Glyph.h"

class MonoGlyph: public Glyph{
    public:
        virtual void Draw(/*Window**/){}
};

class Border: public MonoGlyph{
    void Draw(/*Window**/){}
    void DrawBorder(/*Window**/){}
};

class Scroller: public MonoGlyph{
    void Draw(/*Window**/){}
};