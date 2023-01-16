template<class type>
class Stack{
    public:
        virtual bool isEmpty() const = 0;
        virtual bool isFull() const = 0;
        virtual void push(const type &elem) = 0;
        virtual void pop() = 0;
        virtual type top() = 0;
};