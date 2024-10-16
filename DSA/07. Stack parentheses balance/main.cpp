#include <iostream>
#include "StackLL.h"
#include <string>
using namespace std;

void is_balanced_parentheses(string str);
int main(){
    string str1 = "{[()]}"; 
    string str2 = "][(){}"; 
    string str3 = "{](){}[}"; 
    string str4 = "()()()[][][]{}{}{}"; 
    string str5 = "([](){}{}{}";
    string str6 = "(()()(()";
    is_balanced_parentheses(str1);
    is_balanced_parentheses(str2);
    is_balanced_parentheses(str3);
    is_balanced_parentheses(str4);
    is_balanced_parentheses(str5);
    is_balanced_parentheses(str6);
    
}

void is_balanced_parentheses(string str){ //int ni dapat
    ListS *list = new StackLL();
    cout << str << endl;
    
    for(int i = 0; i < str.length(); i++){
        char c = str[i];

        if(c == '{' || c == '[' || c == '('  ){
            list->push(c);
        } else{
            if(list->isEmpty()){
                cout << "Lacks Opening" << endl;
                return;
            }

            switch(list->top()){
                case '{':
                    if(c == '}'){
                        list->pop();
                    } else{
                        cout << "Mismatch" << endl;
                        return;
                    }
                    break;
                case '[':
                    if(c == ']'){
                        list->pop();
                    } else{
                        cout << "Mismatch" << endl;
                        return;
                    }
                    break;
                case '(':
                    if(c == ')'){
                        list->pop();
                    } else{
                        cout << "Mismatch" << endl;
                        return;
                    }
                    break;
            }
        }
    }

    if(list->isEmpty()){
        cout << "balanced" << endl;
    } else{
        if(list->top() == '{' || list->top() == '[' || list->top() == '('){
            cout << "Lacks closing" << endl;
        } else{
            cout << "Lacks opening" << endl;
        }
    }


}

