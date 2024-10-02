#include <iostream>
#include <cstdlib>
#include "list.h"
#include "node.h"
using namespace std;

class Linkedlist: public List{
    node *head = NULL;
    node *tail = NULL;
    node *n = (node*) calloc(1, sizeof(node));
    int size = 0;

    public:

    void addHead(int num){
        node *n = (node*) calloc(1, sizeof(node));
        n->data = num;

        n->next = head; //stores the address of the previous head

        if(!head){    //if no element set both head and tail to n;
            tail = n;
        }

        head = n; //sets a new head

        size++;
    }

    void addTail(int num){
        node *n = (node*) calloc(1, sizeof(node));
        n->data = num;
        n->next = nullptr; //optional since we're using calloc 

        if(!head){
            head = n;
        }

        if(tail){
            tail->next = n; // sets the tail of the previous tail to n;
        }

        tail = n; //sets a new tail

        size++;
    }

    void addAt(int num, int pos){
        node *n = (node*) calloc(1, sizeof(node));

        n->data = num;

        if(pos == 1){
            n->next = head;
            head = n;

            if(!tail){
                tail = n;
            }
        } else{
            node *current = head;
            node *previous = nullptr;

            for(int i = 1; i < pos; i++){
                previous = current;
                current = current->next;
            }

            n->next = current;
            previous->next = n;
            
            if(n->next == nullptr){
                tail = n;
            }
        }

        size++;
    }

    int remove(int num){
        node *current = head;
        node *previous = nullptr;
        int ctr = 1;

        while(current){
            if(current->data == num){
                if(current == head){
                    head = head->next;
                } else if(current == tail){
                    previous->next = nullptr;
                    tail = previous;
                } else{
                    previous->next = current->next;
                }
                size--;
                return ctr;
            }
            previous = current;
            current = current->next;
            ctr++;
        }

        return -1;
    }

    int removeAt(int pos){
        node *current = head;
        node *previous = nullptr;
        int value = 0;
        int ctr = 1;

        while(current){
            if(ctr == pos){
                value = current->data;

                if(current == head){
                    head = head->next;
                } else if(current == tail){
                    previous->next = nullptr;
                    tail = previous;
                } else{
                    previous->next = current->next;
                }

                size--;
                return value;
            } 

            previous = current;
            current = current->next;
            ctr++;
        }
       

        return 0;
    }
    
    int removeAll(int num){
        node *current = head;
        node *previous = nullptr;
        node *nextNode = nullptr;

        int ctr = 0;

        while(current){
            if(current->data == num){
                //needed when whe free the current node
                nextNode = current->next;

                //if current is head
                if(current == head){
                    head = head->next;
                    //if current is head and also tail
                    if(current == tail){
                        tail = nullptr;
                    }
                } else if(current == tail){
                    //if current is tail
                    previous->next = nullptr;
                    tail = previous;

                } else{
                    //             also the previous->next    
                    // [previous] ------> [current] ------> [nextNode]
                    //                              also the current->next
                    previous->next = current->next;
                }
                free(current);
                size--;
                ctr++;
                
                current = nextNode;
            } else{
                previous = current;
                current = current->next;
            } 
        }
        return ctr;

    }

    void print(){

        if(size == 0){
            cout << "No elements: " << endl;
            return;
        }
        node *curr = head;

        int i = 1;
        while(curr){
            cout << "\nAddress of node " << i << ": " << curr << endl;
            cout << "Element of node " << i << ": " << curr->data << endl;
            cout << "\nAddress linked to node " << i << ": " << curr->next << endl;

            i++;
            curr = curr->next;
        }
    }

    int getSum(){
        node* current = head;
        int sum = 0;

        while(current){
            sum += current->data;
            current = current->next;
        }

        return sum;
    }

    double getAverage(){
        node* current = head;
        float sum = 0.0;
        int ctr = 0;

        while(current){
            sum += current->data;
            ctr++;
            current = current->next;
        }

        return sum / ctr;
    }
};