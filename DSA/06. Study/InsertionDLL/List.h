struct node{
    int elem;
    node *prev;
    node *next;
};

class List{
    public:
    virtual void addBetween(int num, node *pred, node *succ) = 0;
    virtual void addHead(int num) = 0;
    virtual void addTail(int num) = 0;
    virtual int add(int num) = 0;
    virtual void print() = 0;

};

