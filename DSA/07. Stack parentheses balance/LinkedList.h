#include <iostream>
#include "List.h"

struct node{
    char elem;
    node *next;
};

class LinkedList: public List{
    node *head;
    node *tail;
    int size;

    public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void addHead(char c){
        node *n = new node;
        n->elem = c;

        if(head == nullptr){
            head = n;
            tail = n;
            tail->next = nullptr;
        } else{
            n->next = head;
            head = n;
        }
        size++;
    }
    int removeHead(){
        if(head == nullptr){
            return -1;
        } 
        
        node *temp = head;
        char hold = head->elem;
        head = head->next;
        delete temp;
        size--;

        if(!head){
            head == nullptr;
            tail = nullptr;
            size = 0;
        }

        return hold;
        
    }
    char getHead(){
        if(head == nullptr){
            return -1;
        }

        return head->elem;
    }

    int getSize(){
        return size;
    }
};