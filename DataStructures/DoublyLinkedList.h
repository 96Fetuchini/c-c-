#include<iostream>

template<class type>
class dlnode{
    public:
        type info;
        dlnode<type>* next;
        dlnode<type>* prev;
};

template<class type>
class DoublyLinkedList{
    private:
        void copy(const DoublyLinkedList<type> &dll){
            clear();
        }
    protected:
        bool empty;
        int nodeCount;
        dlnode<type>* first;
        dlnode<type>* last;
    public:
        //constructors
        DoublyLinkedList(){
            empty = true;
            nodeCount = 0;
            first = NULL;
            last = NULL;
        }
        ~DoublyLinkedList(){
            clear();
        }
        void print(){
            if(!empty){
                dlnode<type>* aux = first;
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
        //access
        dlnode<type>* &getFirst(){
            return first;
        }
        dlnode<type>* &getLast(){
            return last;
        }
        bool search(const type& elem){
            dlnode<type>* i = first;
            while(i != NULL){
                if(i->info == elem)
                    return true;
                i = i->next;
            }
            return false;
        }
        // capacity
        bool isEmpty(){
            return empty;
        }
        int getSize() const{
            return nodeCount;
        }
        //modifiers
        void clear(){
            while (first != last){
                last = last->prev;
                delete last->next;
                last->next = NULL;
            }
            delete first;
            empty = true;
            nodeCount = 0;
            first = NULL;
            last = NULL;
        }
        void insert(const type& elem){
            dlnode<type>* newNode = new dlnode<type>;
            newNode->info = elem;
            newNode->next = NULL;
            newNode->prev = NULL;
            if(first == NULL){
                first = newNode;
                last = first;
            }
            else{
                newNode->prev = last;
                last->next = newNode;
                last = newNode;
            }
            nodeCount = nodeCount + 1;
            if(0 < nodeCount)
                empty = false;
        }
        
        void erase(const int& aux){
            if(!empty){
                dlnode<type>* auxNode = first;
                if(0 < aux % nodeCount){
                    for(int i = 0; i < aux % nodeCount; i++)
                        auxNode = auxNode->next;
                }
                //brilliant =)
                if(auxNode->prev != NULL) //not first
                    auxNode->prev->next = auxNode->next;
                else
                    first = auxNode->next;
                if(auxNode->next != NULL)//not last
                    auxNode->next->prev = auxNode->prev;
                else    
                    last = auxNode->prev;
                delete auxNode;
                nodeCount = nodeCount - 1;
                if(nodeCount == 0)
                    empty = true;
            }
        }
};

template<class type>
class DoublyLinkedListIterator{
    private:
        dlnode<type>* current;
    public:
        DoublyLinkedListIterator(){
            current = NULL;
        }
        DoublyLinkedListIterator(dlnode<type>* p){
            current = p;
        }
        DoublyLinkedListIterator(DoublyLinkedList<type> &dll){
            current = dll.getFirst();
        }
        type operator*(){
            return current->info;
        }
        DoublyLinkedListIterator<type>& operator++(){
            if(current != NULL)
                current = current->next;
            return *(this);
        }
        DoublyLinkedListIterator<type>& operator--(){
            if(current != NULL)
                current = current->prev;
            return *(this);
        }
        bool operator== (const DoublyLinkedListIterator<type>dlli) const{
            return (current == dlli.current);
        }
        bool operator!= (const DoublyLinkedListIterator<type>dlli) const{
            return (current != dlli.current); 
        }
}; 

