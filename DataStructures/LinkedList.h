#include"List.h"

template<class type>
class LinkedList: public List<type>{
    
    public:
        bool search(const type& info){
            return true;
        }
        //modifiers
        void insert(const type& info){
            if(List<type>::first == NULL){
                List<type>::last = new node<type>;
                List<type>::first = List<type>::last;
                List<type>::empty = false;
            }
            else{
                List<type>::last->next = new node<type>;
                List<type>::last = List<type>::last->next;
            }
            List<type>::last->info = info;
            List<type>::last->next = NULL;
            List<type>::nodeCount = List<type>::nodeCount + 1;
        }
        void erase(const int& i){
            if(!List<type>::empty){
                node<type>* aux1 = List<type>::first;
                node<type>* aux2 = NULL;
                if(0 < i % List<type>::nodeCount){
                    for(int j = 0; j < (i % List<type>::nodeCount) - 1; j++)
                        aux1 = aux1->next;
                    aux2 = aux1->next;
                    if(aux1->next->next != NULL)
                        aux1->next = aux1->next->next;
                    else    
                        aux1->next = NULL;
                    aux1 = aux2;
                }
                else{
                    aux1 = List<type>::first;
                    List<type>::first = List<type>::first->next;
                }
                delete aux1;
                List<type>::nodeCount = List<type>::nodeCount - 1;
                if(List<type>::nodeCount < 1) 
                    List<type>::empty = true;
            }
        }
        //void push(const type& info){}
        //void pop(const type& info){}
        //operations?
        
};
template<class type>
class LinkedListIterator{
    private:
        node<type>* current;
    public:
        LinkedListIterator(){
            current = NULL;
        }
        LinkedListIterator(node<type>* p){
            current = p;
        }
        LinkedListIterator(const LinkedList<type> &ll){
            current = ll.getFirst();
        }
        type operator*(){
            return current->info;
        }
        LinkedListIterator<type>& operator++(){
            if(current != NULL)
                current = current->next;
            return *(this);
        }
        bool operator== (const LinkedListIterator<type>lli) const{
            return (current == lli.current);
        }
        bool operator!= (const LinkedListIterator<type>lli) const{
            return (current != lli.current); 
        }
};  