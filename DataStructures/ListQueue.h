#include<iostream>
#include"Queue.h"
#include"LinkedList.h"

template<class type>
class ListQueue: public Queue<type>{
    protected:
        LinkedList<type> ll;
    public:
        ListQueue(){
            ll = LinkedList<type>();
        }
        ~ListQueue(){}
        void print(){
            ll.print();
        }
        bool isEmpty() const{
            return ll.isEmpty();
        }
        bool isFull() const{
            return false;//this queue can have infinite elements
        }
        void push(const type &elem){
            ll.insert(elem);
        }
        void pop(){
            ll.erase(0);
        }
        type front(){
            return ll.List<type>::getFirst()->info;
        }
};