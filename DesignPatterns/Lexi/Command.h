
class Command{
    private:

    protected://cannot be an instance out of the command hierarchy
        Command();
    public:
        virtual ~Command();
        virtual void Execute() = 0;
};

// we will make a different command for each possible action in the app
/*
class Open: public Command{
    private:
    public:
        Open();
        void Execute(){}
};
class Save: public Command{
    private:
    public:
        Save();
        void Execute(){}
};
class Print: public Command{
    private:
    public:
        Print();
        void Execute(){}
};
class Copy: public Command{
    private:
    public:
        Copy();
        void Execute(){}
};
class Paste: public Command{
    private:
    public:
        Paste();
        void Execute(){}
};
*/
//Event Activated Commands
class Insert: public Command{
    private:
    public:
        Insert();
        void Execute(){
            
        }
};

class PutCursor: public Command{
    private:
    public:
        PutCursor();
        void Execute(){
            
        }
};
class Erase: public Command{
    private:
    public:
        Erase();
        void Execute(){}
};
class ScrollDown: public Command{
    private:
    public:
        ScrollDownCommand();
        void Execute(){}
};
class ScrollUp: public Command{
    private:
    public:
        EraseCommand();
        void Execute(){}
};