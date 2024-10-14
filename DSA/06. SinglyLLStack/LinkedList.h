#include <iostream>
#include <cstdlib>
#include "List.h"

struct node{
    int elem;
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

    void addHead(int num){
        node *n = new node();
        n->elem = num;

        if(head == nullptr){
            n->next = nullptr;
            head = n;
            tail = n;
            
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
        int hold = head->elem;
        head = head->next;
        free(temp);
        size--;
        return hold;
        
    }
    
    int getSize(){
        return size;
    }
    
    int getHead(){
        if(head == nullptr){
            return -1;
        }
        
        return head->elem;
    }
};  