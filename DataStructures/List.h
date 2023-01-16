#include<iostream>
/*this is an abstract class that is going 
to be implemented to create any type of list*/

template<class type>
class node{
    public:
        type info;
        node<type>* next;
};

template<class type>
class List{
    private:
        void copy(const List<type> &ll){
            clear();
            node<type>* aux = NULL;
            nodeCount = ll.nodeCount;
            empty = ll.empty;
            first = NULL;
            last = NULL;
            if(!empty){
                first = new node<type>;
                aux = ll.first;
                first->info = aux->info;
                first->next = NULL;
                last = first;
                for(int i = 1; i < nodeCount; i++){
                    last->next = new node<type>;
                    last = last->next;
                    aux = aux->next;
                    last->info = aux->info;
                    last->next = NULL;
                }
            }
        }
    protected:
        int nodeCount;
        bool empty;
        node<type> *first;
        node<type> *last;
    public:
        List(){
            nodeCount = 0;
            empty = true;
            first = NULL;
            last = NULL;
        }
        List(const List<type> &ll){
            copy(ll);
        }
        ~List(){
            clear();
        }
        void print() const{
            if(!empty){
                node<type>* aux = first;
                std::cout << "[" ;
                for(int i = 0; i < nodeCount - 1; i++){
                    std::cout << aux->info << ", ";
                    aux = aux->next;
                }
                std::cout << aux->info << "]" <<std::endl;
            }
            else
                std::cout << "[empty]" << std::endl; 
        }
        //capacity
        bool isEmpty() const{
            return empty;
        }
        int getSize() const{
            return nodeCount;
        }
        //access
        node<type>* &getFirst(){
            return first;
        }
        node<type>* &getLast(){
            return last;
        }
        virtual bool search(const type& elem) = 0;
        //modifiers
        virtual void insert(const type& elem) = 0;
        virtual void erase(const int& aux) = 0;
        void clear(){
            if(!empty){
                node<type>* aux;
                while(first != last){
                    aux = first;
                    first = first->next;
                    delete aux;
                }
                delete first;
                first = NULL;
                last = NULL;
            }
            nodeCount = 0;
            empty = true;
        }
        void swap(List<type>& ll){
            //first we copy this list
            node<type>* aux = NULL;
            int auxNodeCount = nodeCount;
            bool auxEmpty = empty;
            node<type>* auxFirst = NULL;
            node<type>* auxLast = NULL;
            if(!auxEmpty){
                node<type>* aux = first;
                auxFirst = new node<type>;
                auxFirst->info = aux->info;
                auxFirst->next = NULL;
                auxLast = auxFirst;
                for(int i = 1; i < nodeCount; i++){
                    auxLast->next = new node<type>;
                    auxLast = auxLast->next;
                    aux = aux->next;
                    auxLast->info = aux->info;
                    auxLast->next = NULL;
                }
            }
            //then we copy ll into this list
            copy(ll);
            //then we copy what the list had back to ll
            ll.nodeCount = auxNodeCount;
            ll.empty = auxEmpty;
            ll.first = auxFirst;
            ll.last = auxLast;

            auxFirst = NULL;
            auxLast = NULL;
        }   
        //operations
        void sortAscendent(){
            if(!empty){
                node<type>* pre = NULL;
                node<type>* swap = NULL;
                node<type>* i = first;
                node<type>* j = NULL;
                bool finish = false;
                //node<type>* iter = List<type>* first;
                //search and quit element
                while(i != NULL && !finish){
                    if(i->next != NULL){//2 or more
                        if(pre == NULL){//first elem of the list
                            if(i->next->info < i->info){
                                swap = i;
                                i = i->next;
                                first = i;
                            }
                            else
                                break;
                        }
                        else{ // after the first elem in the list
                            if(i->next->info < i->info){
                                swap = i;
                                pre->next = i->next;
                                swap->next = NULL;
                            }
                        }
                        pre = NULL;
                        j = first;
                        while(j != NULL){
                            if(pre == NULL){//first element
                                if(j->next == NULL){//if there are 2 unordered elements
                                    j->next = swap;
                                    swap->next = NULL;
                                    first = j;
                                }
                                else{//if there are more than 2 unordered elements
                                    if(swap->info < j->info){
                                        swap->next = j;
                                        first = swap;
                                        break;
                                    }
                                }
                            }
                            else{
                                if(j->next == NULL){
                                    j->next = swap;
                                    swap->next = NULL;
                                    last = swap;
                                }
                                else{
                                    if(swap->info <= j->info){
                                        swap->next = j;
                                        pre->next = swap;
                                        finish = true;
                                        break;
                                    }
                                }
                            }
                            pre = j;
                            j = j->next;
                        }
                        pre = NULL;
                    }
                    pre = i;
                    i = i->next;
                }
                //put element back
            }
        }
        void sortDescendent(){
            if(!empty){
                node<type>* pre = NULL;
                node<type>* swap = NULL;
                node<type>* i = first;
                node<type>* j = NULL;
                bool finish = false;
                //node<type>* iter = List<type>* first;
                //search and quit element
                while(i != NULL && !finish){
                    if(i->next != NULL){//2 or more
                        if(pre == NULL){//first elem of the list
                            if(i->info <= i->next->info){
                                swap = i;
                                i = i->next;
                                first = i;
                            }
                            else
                                break;
                        }
                        else{ // after the first elem in the list
                            if(i->info <= i->next->info){
                                swap = i;
                                pre->next = i->next;
                                swap->next = NULL;
                            }
                        }
                        pre = NULL;
                        j = first;
                        while(j != NULL){
                            if(pre == NULL){//first element
                                if(j->next == NULL){//if there are 2 unordered elements
                                    j->next = swap;
                                    swap->next = NULL;
                                    first = j;
                                }
                                else{//if there are more than 2 unordered elements
                                    if(j->info <= swap->info){
                                        swap->next = j;
                                        first = swap;
                                        finish = true;
                                        break;
                                    }
                                }
                            }
                            else{
                                if(j->next == NULL){
                                    j->next = swap;
                                    swap->next = NULL;
                                    last = swap;
                                }
                                else{
                                    if(j->info < swap->info){
                                        swap->next = j;
                                        pre->next = swap;
                                        finish = true;
                                        break;
                                    }
                                }
                            }
                            pre = j;
                            j = j->next;
                        }
                        pre = NULL;
                    }
                    pre = i;
                    i = i->next;
                }
                //put element back
            }
        }
};
