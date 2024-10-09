#include <iostream>
#include "circly.h"
using namespace std;

int main(){
    Circular list;
    list.addFirst(3);
    list.addFirst(2);
    list.addFirst(1);
    list.addLast(4);
    list.addLast(5);
    list.print();
    list.rotate(1);
    list.print(); 

}