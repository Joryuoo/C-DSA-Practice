#include <iostream>
using namespace std;

struct node{
    int elem;
    node *next;
};

class Circular{
    
    node *tail;
    int size;
    public: 
    Circular(){
        tail = nullptr;
        size = 0;
    }

    void addFirst(int num){
        node *n = new node();
        n->elem = num;

        if(tail == nullptr){ //if no tail
            tail = n; 
            tail->next = n;
        } else{
            n->next = tail->next;
            tail->next = n;
        }
        size++;
    }

    void addLast(int num){
        node *n = new node();
        n->elem = num;

        if(tail == nullptr){
            tail = n;
            tail->next = n;
        } else{
            n->next = tail->next;
            tail->next = n;
            tail = n;
        }
        size++;
    }

    void rotate(int num){
        if(tail == nullptr){
            cout << "List is empty" << endl;
        } else if(num > size || num == 0){
            cout << "Can't rotate" << endl;
        } else{
            cout << "Rotate" << endl;
            while(num > 0){
                tail = tail->next;
                num--;
            }
        }

        return;
    }

    void print(){
        if(tail == nullptr){
            cout << "List is empty" << endl;
        } else{
            
            node *curr = tail->next;
            do{
                if(curr == tail){
                    cout << curr->elem << " ";
                } else{
                    cout << curr->elem << " -> ";
                }  
                curr = curr->next;
            }while(curr != tail->next);

            cout << "| Tail = " << tail->elem << " | Tail->next = " << tail->next->elem << " |"<< endl;
        }
    }
};