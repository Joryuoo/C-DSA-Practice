#include <iostream>
#include "SentinelList.h"
using namespace std;
int main(){
    List *list = new LinkedList();
    int choice, num, pos, res, left, right;
    char c;

    do{
        choice = 0, num = 0, pos = 0, res = 0, left = 0, right = 0;
        cout << "---------------------------------------------" << endl;
        cout << "[1] addHead\t[2] addTail\t[3] addAt" << endl;
        cout << "[4] get    \t[5] remove\t[6] removeAt" << endl;
        cout << "[7] removeAll\t[8] retain\t[9] corner" << endl;
        cout << "[10] print\t[0] exit" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter element to be added at head: ";
                cin >> num;
                list->addHead(num);
            break;

            case 2:
                cout << "Enter element to be added at tail: ";
                cin >> num;
                list->addTail(num);
            break;
            case 3:
                cout << "Enter element: ";
                cin >> num;
                cout << "Enter position: ";
                cin >> pos;
                list->addAt(pos, num);
            break;

            case 4:
                cout << "Enter position: ";
                cin >> pos;
                res = list->get(pos);

                if(res < -1){
                    cout << "Invalid position!" << endl;
                } else if(res == -1){
                    cout << "List is empty." << endl;
                } else {
                    cout << "The value at position " << pos << " is " << res << endl;
                }
            break;

            case 5:
                cout << "Enter the element you want to remove: ";
                cin >> num;
                res = list->remove(num);

                if(res < 0){
                    cout << "List is empty." << endl;
                } else if(res == 0){
                    cout << "No " << num << " found in the list." << endl;
                } else{
                    cout << num << " was removed at position " << res << endl;
                }
            break;

            case 6:
                cout << "Enter the position you want to remove: ";
                cin >> pos;
                res = list->removeAt(pos);

                if(res <= 0){
                    cout << "Nothing to remove." << endl;
                } else{
                    cout << res << " was removed at position " << pos << endl;
                }
            break;

            case 7:
                cout << "Enter element you want to remove: ";
                cin >> num;

                cout << list->removeAll(num) << " element(s) removed." << endl;
            break;

            case 8:
                cout << "Enter element: ";
                cin >> num;

                cout << list->retain(num) << " element(s) removed." << endl;
            break;

            case 9:
                cout << "Enter corner (left): ";
                cin >> left;
                cout << "Enter corner (right): ";
                cin >> right;

                res = list->corner(left, right);

                if(res < 0){
                    cout << "Invalid corners." << endl;
                } else{
                    cout << res << " element(s) removed." << endl;
                    list->fromHead();
                }
            break;

            case 10: 
                cout << "From ([h] head [t] tail): ";
                cin >> c;

                if(tolower(c) == 'h'){
                    list->fromHead();
                } else if(tolower(c) == 't'){
                    list->fromTail();
                } else{
                    cout << "Invalid Input!" << endl;
                }
            break;

            case 0:
                cout << "Goodbye!" << endl;
                return 0;
            break;
            default:
                cout << "Invalid input!" << endl;
        }

    }while(true);
}