#include <iostream>
#include "node.h"
#include "list.h"
using namespace std;

class Linked: public List{
    private: 
        node* head = nullptr;
        node* tail = nullptr;
        int size = 0;

    public:
        void addFirst(int num){
            node* n = (node*) calloc(1, sizeof(node));
            n->data = num; // stores num to the data

            if(!head){
                tail = n; // if no head then set the tail into n;
            }
            n->next = head; // store the previous head;
            head = n; // sets the new head
            size++;

        }
        void addLast(int num){
            node* n = (node*) calloc(1, sizeof(node));
            n->data = num;

            if(!head){
                head = n;
                tail = n;
            }
            
            if(tail){
                tail->next = n; // links the previous tail to n;
            }

            tail = n; // sets n as the new tail;
            size++;
        }
        int getMiddle(){
            if(size < 3){
                cout << "No middle element" << endl << endl;
            } else{
                node *curr = head;
                for(int i = 1; i <= size/2; i++){
                    curr = curr->next;
                    if(size % 2 == 0){
                        if(i == size/2 -1){
                            return curr->data;
                        }
                    }  else {
                        if(i == size/2){
                            return curr->data;
                        }
                    }
                    
                }
            }

            return 0;
        }
        void reverse(){
            node *curr = head;
            node *prev = nullptr;       //at the first iteration this will make the head node to point to NULL
            node *nextNode = nullptr;

            while(curr){                //stops when curr is null
                nextNode = curr->next;  //stores the address of the next node
                curr->next = prev;      //reverse the current node's pointer
                prev = curr;            //move the prev to curr
                curr = nextNode;        //move3 curr to next node
            }

            head = prev;                //assign the last node as the head node
        }

        void displayNode(){
            node* curr = head;
            int i = 1;
            while(curr){
                cout << "Node " << i << " = " << curr->data << endl;   
                curr = curr->next;   
                i++;        
            }
            cout << endl;
        }
};