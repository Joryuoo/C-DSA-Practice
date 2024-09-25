class List{
    public:
        virtual void addHead(int num) = 0;
        virtual void addTail(int num) = 0;
        virtual void addAt(int pos, int num) = 0;
        virtual int remove(int num) = 0;
        virtual int removeAt(int pos) = 0;
        virtual int removeAll(int num) = 0;
        virtual int retain(int num) = 0;
        virtual int corner(int left, int right) = 0;
        virtual void printFromHead() = 0;
        virtual void printFromTail() = 0;
        virtual void menu() = 0;     
};

