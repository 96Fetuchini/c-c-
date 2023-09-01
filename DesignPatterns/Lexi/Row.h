#include "Character.h"

class Row: public Glyph{
    private:
        Glyph* parent, *child, *mostRecent;
        LinkedList<Glyph*> simbols;
        bool isFull;
    public:
        Row(){
            this->pos = wxPoint(0, 0);
            this->parent = NULL;
            this->child = NULL;
            this->mostRecent = NULL;
        }
        void Draw(Window* w, const wxPoint& pos0){
            LinkedListIterator<Glyph*> it;
            wxPoint lastPos = pos + pos0;
            int size = w->getSize().width;
            /*
            for(it = LinkedListIterator<Glyph*>(simbols.getFirst()); 
                    it != LinkedListIterator<Glyph*>(simbols.getLast()); 
                        ++it){
                (*it)->Draw(w, lastPos);
                //arreglar ese 20
                if(lastPos.x < size - 20){
                    lastPos.x = lastPos.x + (*it)->bounds.width;
                }
                else{
                    lastPos.x = pos0.x;
                    lastPos.y = lastPos.y + (*it)->bounds.height;
                }
            }
            (*it)->Draw(w, lastPos);*/
            simbols.getLast()->info->Draw(w, wxPoint(0,0));
        }
        void Bounds(wxRect& b){
            b = this->bounds;
        }
        //hit detection
        bool Intersects(const wxPoint&){
            return true;
        }
        //structure 
        void Insert(Glyph* g, const wxPoint& pos0){
            simbols.insert(g);
            if(mostRecent == NULL){
                simbols.getLast()->info->Insert(g, pos0);
            }
            else{
                std::cout<<"most Recent != NULL" << std::endl;
                
                std::cout << "most Recent pos = (" << mostRecent->pos.x <<", ";
                std::cout << mostRecent->pos.y << ")" <<std::endl;
                simbols.getLast()->info->Insert(
                    g, wxPoint(mostRecent->pos.x + mostRecent->bounds.width, 0)
                );
            }
            std::cout << "c.pos = (" << simbols.getLast()->info->pos.x <<", ";
            std::cout << simbols.getLast()->info->pos.y << ")" <<std::endl;
            mostRecent = g;
            std::cout << this->pos.x << std::endl << this->pos.y << std::endl;
        }
        void Remove(Glyph* g){}
        Glyph* Child(){
            return NULL;
        }
        Glyph* Parent(){
            return NULL;
        }
};