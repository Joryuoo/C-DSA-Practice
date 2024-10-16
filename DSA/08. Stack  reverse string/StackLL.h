#include <iostream>
#include "ListS.h"
#include "LinkedList.h"
using namespace std;

class StackLL: public ListS{
    List * list;

    public:
    StackLL(){
        list = new LinkedList();
    }

    void push(char c){
        list->addHead(c);
    }
    char pop(){
        return list->removeHead();
    }
    char top(){
        return list->getHead();
    }
    bool isEmpty(){
        return size() == 0;
    }
    int size(){
        return list->getSize();
    }

    void print(){
        list->display();
    }

};