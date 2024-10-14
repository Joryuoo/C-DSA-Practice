#include <iostream>
#include <cstdlib>
#include "ListS.h"
#include "LinkedList.h"
using namespace std;

class SinglyStack: public ListS{
    List *list;

    public:
    SinglyStack(){
        list = new LinkedList();
    }

    void push(int num){
        list->addHead(num);
    }

    int pop(){
        return list->removeHead();
    }
    int top(){
        return list->getHead();
    }

    int size(){
        return list->getSize();
    }

    bool isEmpty(){
        if(size() == 0){
            return true;
        }
        return false;
    }
};