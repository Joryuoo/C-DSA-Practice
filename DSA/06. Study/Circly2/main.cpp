#include <iostream>
#include "Circly.h"
using namespace std;

int main(){
    Circly list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    list.print();
    list.remove(5);
    list.print();
    list.remove(4);
    list.print();
    list.remove(3);
    list.print();
    list.remove(2);
    list.print();
    list.remove(1);
    list.print();
    list.add(1);
    list.add(2);
    list.add(3);
    list.print();
    list.removeFirst();
    list.print();
    list.removeFirst();
    list.removeFirst();
    list.print();
}