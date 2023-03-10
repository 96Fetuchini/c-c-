#include<iostream>
#include"Stack.h"
#include"LinkedList.h"

template<class type>
class ListStack : public Stack<type>{
    protected:
        LinkedList<type> ll;
    public:
        ListStack(){
            ll = LinkedList<type>();
        }
        ~ListStack(){}
        void print(){
            ll.print();
        }
        bool isEmpty() const{
            return ll.isEmpty();
        }
        bool isFull() const{
            return false;//this stack can have infinite elements
        }
        void push(const type &elem){
            ll.insert(elem);
        }
        void pop(){
            ll.erase(ll.List<type>::getSize() - 1);
        }
        type top(){
            return ll.List<type>::getFirst()->info;
        }
};