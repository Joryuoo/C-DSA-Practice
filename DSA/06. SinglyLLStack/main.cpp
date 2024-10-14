#include <iostream>
#include "SinglyStack.h"
using namespace std;

void display();
int main(){
    ListS *list = new SinglyStack();
    int choice = 0;
    int num = 0;
    int res = 0;
    while(true){
        choice = 0, num = 0, res = 0;
        display();
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter a number to push into the stack: ";
                cin >> num;
                list->push(num);
                break;
            case 2:
                res = list->pop();
                if(res < 0){
                    cout << "The stack is empty." << endl;
                } else{
                    cout << res << " was popped out of the stack." << endl;
                }
                break;
            case 3:
                res = list->top();
                if(res < 0){
                    cout << "The stack is empty." << endl;
                } else{
                    cout << "The element at the top is " << res << endl;
                }
                break;
            case 4:
                cout << "Size: " << list->size() << endl;
                break;
            case 5:
                if(list->isEmpty()){
                    cout << "Empty" << endl;
                } else{
                    cout << "Not empty" << endl;
                }
                break;
        }
    }
    
}

void display(){
    cout << "------------------------------------------" << endl;
    cout << "[1] Push\t[2] Pop\t\t[3] Top" << endl;
    cout << "[4] Size\t[5] isEmpty\t[6] Exit" << endl;
    cout << "------------------------------------------" << endl;
}