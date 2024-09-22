#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(){
    List *list = new Linked();

    list->addFirst(1);
    list->addLast(2);
    list->addLast(3);
    list->addLast(4);
    list->addLast(5);
    list->addLast(6);
    list->addLast(7);
    list->addLast(8);
    list->addLast(9);
    list->addLast(10);
    list->displayNode();
    cout << "Middle: " << list->getMiddle() << endl << endl;

    cout << "Reverse!" << endl << endl;
    list->reverse();
    list->displayNode();
   

    
}