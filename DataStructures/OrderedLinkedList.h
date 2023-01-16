#include "List.h"

template<class type>
class OrderedLinkedList: public List<type>{
    protected:
        bool ascendent;
    public:
        OrderedLinkedList():List<type>(){
            ascendent = true;
        }
        int compare(const type &a, const type &b) const{
            return (a < b) && ascendent;
        }
        bool search(const type& elem){
            node<type>* aux = List<type>::first;
            if(!List<type>::empty){
                while(aux != NULL){
                    if(aux->info == elem)
                        return true;
                    aux = aux->next;
                }
            }
            return false;
        }
        type& at(const int& i) const{
            int j = 0;
            node<type>* aux = List<type>::first;
            while(aux != NULL){
                if(j == i % List<type>::nodeCount)
                    break;
                aux = aux->next;
                j = j + 1;
            }
            return aux->info;
        }
        //modifiers
        void insert(const type& elem){
            node<type>* newNode = new node<type>;
            newNode->info = elem;
            newNode->next = NULL;
            if(List<type>::first == NULL){
                List<type>::last = newNode;
                List<type>::first = List<type>::last;
                List<type>::empty = false;
            }
            else{
                newNode->next = List<type>::first;
                List<type>::first = newNode;
            }
            //no me gusta
            if(ascendent)
                List<type>::sortAscendent();
            else
                List<type>::sortDescendent();
            newNode = NULL;
            List<type>::nodeCount = List<type>::nodeCount + 1;
            //it will put the element in order
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
        void setAscendent(){
            ascendent = true;
        }
        void setDescendent(){
            ascendent = false;
        }
};