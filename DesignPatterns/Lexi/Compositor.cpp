#include"Glyph.h"

class Composition : public Glyph{
    protected:
        Compositor format;
    public:
        void insert(Glyph* g, int i) {
            
        }

};

class Compositor{
    public:
        //when to format (moment)
        virtual void Compose(){

        };
        //what to format
        void SetComposition(Composition* comp){

        };
};



