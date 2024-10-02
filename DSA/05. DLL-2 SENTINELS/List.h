#include "node.h"
class List{
    public:
        virtual void addBetween(int num, node *pred, node *succ) = 0;
        virtual void addHead(int num) = 0;
        virtual void addTail(int num) = 0;
        virtual void addAt(int pos, int num) = 0;
        virtual int get(int pos) = 0;
        virtual int remove(int num) = 0;
        virtual int removeAt(int pos) = 0;
        virtual int removeAll(int pos) = 0;
        virtual int retain(int num) = 0;
        virtual int corner(int left, int right) = 0;
        virtual void fromHead() = 0;
        virtual void fromTail() = 0;
};