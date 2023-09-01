#include "Row.h"

class Column: public Glyph{
    private:
        LinkedList<Glyph*> rows;
    public:
        Column(const wxPoint &pos, Glyph* parent){
            this->pos = pos;
            this->parent = parent;
            this->child = NULL;
        }
        void Draw(Window* w, const wxPoint& pos0){
            LinkedListIterator<Glyph*> it(rows.getFirst());
            wxPoint lastPos = pos + pos0;
            for(it = LinkedListIterator<Glyph*>(rows.getFirst()); 
                    it == LinkedListIterator<Glyph*>(rows.getLast()); 
                        ++it){
                (*it)->Draw(w, lastPos);
                lastPos.y = lastPos.y + (*it)->bounds.height;
            }
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
            if(rows.isEmpty()){
                rows.insert(new Row);
                rows.getLast()->info->pos = wxPoint(0, 0) + pos0;
            }
            else{
                //if there is a new line character
            }
            rows.getLast()->info->Insert(g, wxPoint(this->pos + pos0));
        }
        void Remove(Glyph*){
            //we will see what this does
        }
        Glyph* Child(){
            return rows.getFirst()->info;  
        }
        Glyph* Child(int n = 0){
            LinkedListIterator<Glyph*> it = LinkedListIterator<Glyph*>(rows.getFirst());
            for(int i = 0; i < rows.getSize() % n; i++)
                ++it;
            return *it;
        }
        Glyph* Parent(){
            return parent;
        }
};