#include"Glyph.h"

class Compositor{
    public:
        //when to format
        virtual void Compose();
        //what to format
        void SetComposition();
};

class ArrayCompositor: public Compositor{
    public:
        void Compose(){}
};
class TeXCompositor: public Compositor{
    public:
        void Compose(){}
};
class SimnpleCompositor: public Compositor{
    public:
        void Compose(){}
};

class Composition : public Glyph{
    protected:
        Glyph* parent;
        Glyph* Child;
        Compositor format;
    public:
        void insert(Glyph* g, int i) {}
};


