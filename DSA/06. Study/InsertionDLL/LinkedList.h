#include <iostream>
#include <cmath>
#include "List.h"
using namespace std;

class LinkedList: public List{
    node *head;
    node *tail;
    int size = 0;

    public: 
    LinkedList(){
        head = new node(); //allocate memory
        tail = new node();
        head->next = tail;
        tail->prev = head;
    }

    void addBetween(int num, node *pred, node *succ){
        node *n = new node();
        n->elem = num;
        n->prev = pred;
        n->next = succ;
        pred->next = n;
        succ->prev = n;
        size++;
    }

    void addHead(int num){
        addBetween(num, head, head->next);
    }

    void addTail(int num){
        addBetween(num, tail->prev, tail);
    }

    int add(int num){
        node *n = new node();

        node *curr = head->next;
        int ctr = 1;

        if(num < head->next->elem){
            addHead(num);
        } else if(num > tail->prev->elem){
            addTail(num);
        } else{
            while(curr != tail){
                if(curr->elem > num){
                    addBetween(num, curr->prev, curr);
                    break;
                } else{
                    curr = curr->next;
                }
                ctr++;
            }

            if(ctr <= ceil(size / 2.0)){
                return 1;
            } else{
                return 2;
            }
        } 
        return 0;
    }

    void print(){
        if(head->next == tail){
            cout << "List is empty" << endl;
            return;
        }

        node *curr = head->next;
        while(curr != tail){
            cout << curr->elem << " -> ";
            if(curr->next == tail){
                cout << "Trailer";
            }
            curr = curr->next;
        }
        cout << endl; 
    }
};

