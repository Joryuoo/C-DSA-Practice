#include <iostream>
#include "Doubly.h"
using namespace std;

int main(){
    Doubly list1, list2;

    // 1ST DLL
    cout << "List 1" << endl;
    list1.add(1);
    list1.add(2);
    list1.add(3);
    list1.add(4);
    list1.add(5);
    list1.print();
    cout << endl;

    // 2ND DLL
    cout << "List 2" << endl;
    list2.add(6);
    list2.add(7);
    list2.add(8);
    list2.add(9);
    list2.add(10);
    list2.print();
    cout << endl;

    list1.combine(&list2);
    cout << "List 1: ";
    list1.print();
    cout << endl;
    cout << "List 2: ";
    list2.print();
    cout << endl;
    list2.combine(&list1);
    cout << "List 1: ";
    list1.print();
    cout << endl;
    cout << "List 2: ";
    list2.print();

    
    

}