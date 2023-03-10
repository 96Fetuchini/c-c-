template<class type>
class Queue{
    public:
        virtual bool isEmpty() const = 0;
        virtual bool isFull() const = 0;
        virtual void push(const type &elem) = 0;
        virtual void pop() = 0;
        virtual type front() = 0;
};