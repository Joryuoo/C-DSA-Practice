#include "Linkedlist.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    List * list = new Linkedlist();
    int op = 0;
    int num = 0;
    int pos = 0;
    int holder = 0;
    bool isOut = false;

    while(!isOut){
    cout << "[1] AddHead\t[2] AddTail\t[3] AddAt " << endl;
    cout << "[4] Remove\t[5] RemoveAt\t[6] RemoveAll " << endl;
    cout << "[7] Print\t[8] Sum    \t[9] Average" << endl;
    cout << "[0] Exit" << endl << endl;
    cout << "Enter operation: ";
    cin >> op;
    
        switch(op){
            case 1:             
                cout << "Enter element you want to add: ";
                cin >> num;
                list->addHead(num);
                break;
            case 2:
                cout << "Enter element you want to add: ";
                cin >> num;
                list->addTail(num);
                break;
            case 3:
                cout << "Enter element you want to add: ";
                cin >> num;
                cout << "Enter position: ";
                cin >> pos;
                list->addAt(num, pos);
                break;
            case 4:
                cout << "Enter element you want to remove: ";
                cin >> num;

                holder = list->remove(num);

                if(holder <= 0){
                    cout <<"There's no such element." << endl; 
                    break;
                }
                cout << num << " was removed at: " << holder << endl; 
                break;
            case 5:
                cout << "Enter the position of the element you want to remove: ";
                cin >> pos;
                holder = list->removeAt(pos);

                if(holder <= 0){
                    cout <<"There's no such position." << endl; 
                    break;
                }

                cout << holder << " was removed." << endl; 
                break;
            case 6:
                cout << "Enter the element you want to remove: ";
                cin >> num;

                holder = list->removeAll(num);

                if(holder <= 0){
                    cout <<"There's no such element." << endl; 
                    break;
                }
                cout << holder << " element(s) was removed." << endl << endl; 
                break;
            case 7:
                cout << "LIST: " << endl;
                list->print();
                break;
            case 8:
                cout << "Sum of all nodes: " << list->getSum() << endl << endl;
                break;
            case 9:
                cout << "The avarage of all nodes: " << fixed << setprecision(2) << list->getAverage() << endl << endl;
                break;
            case 0:
                cout << "Exiting..." << endl;
                isOut = true;
                break;
            default:
                cout << "Invalid Input!" << endl;
                break;
        }
    }   
}
