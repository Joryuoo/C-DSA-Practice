#include <iostream>
#include <string>
using namespace std;

class BankAccount{ //object called BankAccount
    public: // access specifier
        string name; //member variables
        int balance; // member of the class //attributes

        void withdraw(int amount){ //methods
            balance -= amount;
        }
};

int main(){
    BankAccount acc1; // creates a bankaccount object
    acc1.name = "Ryan";
    acc1.balance = 10000;
    int amount;

    cout << "Your account name: " << acc1.name << endl;
    cout << "Your balance is: " << acc1.balance << endl;
    
    cout << "\nEnter amount you want to withdraw: ";
    cin >> amount;

    acc1.withdraw(amount); //this is how to use the methods in the class

    cout << "Your current balance is: " << acc1.balance;
}