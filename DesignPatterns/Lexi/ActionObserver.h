
#ifndef ACTIONOBSERVERDEF
#define ACTINOOBSERVERDEF

class Observer{
    public:     
        virtual void Update();
};

class ActionObserver: public Observer{
    private:
        ActionEvent ae;
    public:
        void Update(const ActionEvent& ae){
            this->ae = ae; 
        }
};

#endif