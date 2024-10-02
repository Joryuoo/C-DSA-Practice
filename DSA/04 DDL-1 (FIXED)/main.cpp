#include <iostream>
#include "doubly.h"
using namespace std;

int main(){
    List * list = new Doubly();
    int choice = 0;
    int num, num2, pos, res, size;
    bool isQuit = false;

    do{
        list->menu();
        cout << "Enter your choice: ";
        cin >> choice;
        num = 0;
        pos = 0;
        res = 0;
        num2 = 0;
        size = 0;

        switch(choice){
            case 1:
                cout << "Enter the data you want to add to the head: ";
                cin >> num;
                list->addHead(num);
                break;
            case 2:
                cout << "Enter the data you want to add to the tail: ";
                cin >> num;
                list->addTail(num);
                break;
            case 3:
                cout << "Enter position: ";
                cin >> pos;
                cout << "Enter data: ";
                cin >> num;
                list->addAt(pos, num);
                break;
            case 4:
                cout << "Enter the element you want to remove: ";
                cin >> num;
                res = list->remove(num);

                if(res < 0){
                    cout << "List is empty." << endl;
                } else if(res == 0){
                    cout << "No " << num << " found in the list" << endl;
                }else{
                    cout << num << " was removed from position " << res << endl;
                    list->fromHead();
                }
                
                break;
            case 5:
                cout << "Enter the position to remove: ";
                cin >> pos;
                res = list->removeAt(pos);

                if(res < 0){
                    cout << "Invalid position." << endl;
                } else if(res == 0){
                    cout << "List is empty." << endl;
                } else{
                    cout << res << " was removed"<< endl;
                    list->fromHead();
                }
                
                break;
            case 6:
                cout << "Enter the element you want to remove: ";
                cin >> num;
                res = list->removeAll(num);

                if(res < 0){
                    cout << "List is empty." << endl;
                }else if(res == 0){
                    cout << "There was nothing to remove." << endl;
                } else{
                    cout << res << " elements were removed"<< endl;
                    list->fromHead();
                }

                break;
            case 7:
                cout << "Enter element: ";
                cin >> num;
                res = list->retain(num);

                if(res < 0){
                    cout << "List is empty." << endl;
                }else if(res == 0){
                    cout << "There was nothing to remove." << endl;
                } else{
                    cout << res << " elements less than " << num << " were removed"<< endl;
                    list->fromHead();
                }
                break;
            case 8:
                cout << "Enter left: ";
                cin >> num;
                cout << "Enter right: ";
                cin >> num2;
                res = list->corner(num, num2);


                if(res == 0){
                    cout << "There was nothing to remove." << endl;
                    list->fromHead();
                }else if(res > 0){
                    cout << res << " elements were removed"<< endl;
                    list->fromHead();
                }    
                break;
            case 9:
                cout << "[1] Print From Head\t[2] Print From Tail" << endl;
                cout << "Enter your choice: ";
                cin >> num;

                if(num == 1){
                    list->fromHead();
                } else if(num == 2){
                    list->fromTail();
                } else {
                    cout << "Invalid Input!" << endl;
                }
                break;
            case 0:
                isQuit = true;
                break;
            default:
                cout << "Invalid input!" << endl;
        }

        if(isQuit){
            break;
        }
        
    }while(true);
   
    
}
