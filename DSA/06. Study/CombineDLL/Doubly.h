#include <iostream>
using namespace std;

struct node{
    int elem;
    node *prev;
    node *next;
};

class Doubly{
    node *tail;
    node *head;
    int size;

    public:
    Doubly(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void add(int num){ //add sa last rani
        node *n = new node();
        n->elem = num;

        if(head == nullptr){
            head = n;
            tail = n;
        } else{
            n->prev = tail;
            n->next = nullptr;
            tail->next = n;
            tail = n;
        }
        size++;
    }

    void combine(Doubly *other){
        //if list2 has no elements
        cout << "Combining..." << endl;
        
        if(other->head == nullptr){
            other->head = nullptr;
            other->tail = nullptr;
            other->size = 0;
            return;
        } else if(head == nullptr){
            head = other->head;
            tail = other->tail;
            tail->next = nullptr;
            head->prev = nullptr;
            
        } else{
            tail->next = other->head;
            other->head->prev = tail;
            tail = other->tail;
        }
        size += other->size;

        other->head = nullptr;
        other->tail = nullptr;
        other->size = 0;
    }

    void print(){
        if(size == 0 || head == nullptr){
            cout << "Size: " << size << endl;
            cout << "List is empty." << endl;
            return;
        }

        node *curr = head;
        while(curr != nullptr){
            cout << curr->elem << " -> ";
            if(curr->next == nullptr){
                cout << "NULL" << endl;
            }
            curr = curr->next;
        }
        cout << "Size: " << size << endl;

    }


};