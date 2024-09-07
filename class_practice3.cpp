#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;

/*
    Bank Account Management: Create a class BankAccount with attributes like account number, 
    account holder name, and balance. Implement methods to deposit, withdraw, and check the balance. 
    Also, include a method to display account details.

*/

class BankAccount{
    public:
        string name;
        int accountNumber;
        double balance;

        void set_balance(double n){
            if(n <= 0){
                balance = 0;
            } else{
                balance = n;
            }
        }

        void deposit(double n){
            balance += n;
        }

        void withdraw(double n){
            balance -= n;
        }

        double check_balance(){
            return balance;    
        }

        void print(){ 
            cout << "\n-----------------------------" << endl;
            cout << "A C C O U N T  D E T A I L S" << endl;
            cout << "-----------------------------" << endl;
            cout << "Accout Name: " << name << endl;
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: " << fixed << setprecision(2) << balance << endl;
            cout << "-----------------------------" << endl;
        }

};

int main(){
    BankAccount acc;
    int choice;
    double money;
    double amount;

    cout << "Enter name: ";
    getline(cin, acc.name);

    cout << "Enter Account Number: ";
    cin >> acc.accountNumber;
    
    cout << "Enter initial balance: ";
    cin >> money;

    acc.set_balance(money);

    bool isContinue = true;

    while(isContinue){
        while(1){
            cin.ignore();

            cout << "\n[1] WITHDRAW  [2]DEPOSIT   [3]CHECK BALANCE \n[4] Display Account Details [5] EXIT" << endl;
            cout << "\nWould you like to: ";
            cin >> choice;

            switch(choice){          
                case 1:   
                    amount = 0;            
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;

                    if(amount > acc.balance){
                        cout << "Insufficient Balance" << endl;
                        break;
                    }
                    acc.withdraw(amount);
                    cout << "The amount of " << amount << " has been successfully withdrawn." << endl;
                    break;

                case 2:
                    amount = 0;
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    acc.deposit(amount);
                    cout << "The amount of " << amount << " has been successfully deposited." << endl;   
                    break;

                case 3: 
                    cout << "Your current balance is " << acc.check_balance() << endl;
                    break;
                case 4: 
                    acc.print();
                    break;
                case 5: 
                    cout << "Thank you for using our service. Goodbye!" << endl;
                    return 0;
                default :
                    cout << "\nInvalid Input! Please Try Again." << endl;

            }
        }
    }

}