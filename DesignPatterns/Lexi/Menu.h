#include "Glyph.h"

class MenuItem{
    private: 
    public:
        MenuItem(){}
        void Clicked(){
            
        }
};

class Menu{
    private:
        LinkedList<MenuItem*> items;
    public:
        Menu(){}
        void add(MenuItem *mi){
            items.insert(mi);
        }
};


