#include <iostream>
#include "StackLL.h"
#include <string>
using namespace std;

void reverse(string str);
int main(){
    string str1 = "The quick brown fox sleeps with the lazy dog";
    string str2 = "I love you 3000";
    reverse(str1);
    reverse(str2);


}

void reverse(string str){
    ListS *list = new StackLL();
    cout << str << endl;

    for(int i = 0; i < str.length(); i++){
        char c = str[i];
        
        if(i == str.length() - 1){
            list->push(toupper(c));
        } else{
            list->push(tolower(c));
        }
        
    }

    cout << "Reverse: ";
    list->print();
    cout << endl;
}

