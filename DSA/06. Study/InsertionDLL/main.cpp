#include <iostream>
#include "LinkedList.h"
int main(){
    List *list = new LinkedList();
    list->addHead(10);
    list->addTail(15);
    list->addTail(20);
    list->addTail(25);
    list->print();

    if(list->add(16) == 1){
        cout << "16 add from head " << endl;

    } else{
        cout << "16 add from tail " << endl;
    }

    list->print();

    if(list->add(11) == 1){
        cout << "11 add from head " << endl;

    } else{
        cout << "11 add from tail " << endl;
    }

    list->print();

    if(list->add(21) == 1){
        cout << "21 add from head " << endl;

    } else{
        cout << "21 add from tail " << endl;
    }

    list->print();

    if(list->add(5) == 1){
        cout << "5 add from head " << endl;

    } else{
        cout << "5 add from tail " << endl;
    }

    list->print();

    if(list->add(50) == 1){
        cout << "50 add from head " << endl;

    } else{
        cout << "50 add from tail " << endl;
    }

    list->print();
    
}