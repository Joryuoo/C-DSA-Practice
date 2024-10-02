#include "List.h"
#include "node.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class Doubly: public List{
    node *head = nullptr;
    node *tail = nullptr;
    int size = 0;

    public:
        void addHead(int num){
            node *n = (node*) calloc(1, sizeof(node));
            n->data = num;
            n->prev = nullptr; // no previous since we're adding at head

            if(!head){
                n->next = nullptr; 
                head = n;
                tail = n;
            }else{
                head->prev = n;
                n->next = head;
                head = n;           
            }
            size++;
        }

        void addTail(int num){
            node* n = (node*) calloc(1, sizeof(node));
            n->data = num;
            n->next = nullptr; 

            if(!tail){
                head = n;
                tail = n;
            } else{
                tail->next = n;
                n->prev = tail;
                tail = n;
            }
            size++;
        }

        void addAt(int pos, int num){

            if(size == 0){
                cout << "No elements in the list" << endl;
                return;
            }

            if(pos < 1 || pos > size + 1){
                cout << "No such position" << endl;
                return;
            }

            if(pos == 1){
                addHead(num); 
            } else{
                node *n = (node*) calloc(1, sizeof(node));
                node *curr = head;
                node *prev = head;

                n->data = num;

                for(int i = 1; i < pos; i++){ //moves curr to that position
                    prev = curr;
                    curr = curr->next; 
                }

                //after curr moves to the given pos
                if(curr == tail){
                    addTail(num);
                } else{
                    n->prev = prev;
                    n->next = curr;
                    prev->next = n;
                    curr->prev = n;
                }
            }
            
            size++;

        }

        int remove(int num){
            node *curr = head;
            node *prev = nullptr;
            node *temp = nullptr;
            int ctr = 1;

            while(curr){
                //if data is found
                if(curr->data == num){
                    temp = curr;
                    //if curr is head
                    if(curr == head){                     
                        head = head->next;
                        head->prev = nullptr;
                        //if curr is also the tail / only one node
                        if(curr == tail){
                            tail = tail->prev;
                            tail->next = nullptr;
                        }
                        // if curr is tail only
                    } else if(curr == tail){
                        tail = curr->prev;
                        tail->next = nullptr;
                    } else{
                        prev->next = curr->next;
                        curr->next->prev = prev;    
                    }
                    free(temp);
                    break;              
                }
                prev = curr;
                curr = curr->next;
                ctr++;
            }

            size--;
            return ctr;           
        }

        int removeAt(int pos){
            node *curr = head;
            node *prev = nullptr;
            node *temp = nullptr;
            int holder = 0;

            //move the curr to the position you want to remove
            for(int i = 1; i < pos; i++){
                prev = curr;
                curr = curr->next;
            }

            holder = curr->data;
            temp = curr;

            if(curr == head){
                head = head->next;
                head->prev = nullptr;
                if(curr == tail){
                    tail = tail->prev;
                    tail->next = nullptr;
                }
            } else if(curr == tail){
                tail = curr->prev;
                tail->next = nullptr;
            } else{
                curr->next->prev = prev;
                prev = curr->next;
            }
            free(temp);
            size--;

            return holder;
        }

        int removeAll(int num){
            node *curr = head;
            node *prev = nullptr;
            node *temp = nullptr;
            int ctr = 0;

            while(curr){
                if(curr->data == num){
                    temp = curr;

                    if(curr == head){
                        head = curr->next;
                        head->prev = nullptr;

                        if(curr == tail){
                            tail = curr->prev;
                            tail->next = nullptr;
                        }
                    } else if(curr == tail){
                        tail = curr->prev;
                        tail->next = nullptr;
                    } else{
                        curr->next->prev = prev;
                        prev->next = curr->next;
                    }

                    ctr++;
                    size--;
                    curr = curr->next;
                    free(temp);
                    //prev = curr;
                    
                } else{
                    prev = curr;
                    curr = curr->next;
                }
                
            }
 
            return ctr;
        }

        int retain(int num){
            node *curr = head;
            //node *prev = nullptr;
            node *temp = nullptr;
            int ctr = 0;

            while(curr){
                if(curr->data < num){
                    temp = curr;
                    if(curr == head){
                        head = head->next;
                        head->prev = nullptr;

                        if(curr == tail){
                            tail = tail->prev;
                            tail->next = nullptr;
                        }
                    } else if(curr == tail){
                        tail = tail->prev;
                        tail->next = nullptr;
                    } else{
                        curr->next->prev = curr->prev;
                        curr->prev->next = curr->next;
                    }

                    ctr++;
                    size--;
                    curr = curr->next;
                    free(temp);
                } else{
                    curr = curr->next;
                }
            }

            return ctr;

        }

        int corner(int left, int right){

            //check if valid left and right inputs
            if(left < 0 || left >= size){
                cout << "Invalid left input";
                return 0;
            }

            if(right < 0 || right >= size){
                cout << "Invalid right input";
                return 0;
            }

            if (left + right >= size) {
                cout << "No corner can be made." << endl;
                return 0;
            }

            //create nodes
            node *currLeft = head;      //for traversing from head to left value
            node *currRight = tail;     // for traversing from tail down to right value
            node *slave = nullptr;      // for freeing the nodes to be deleted
            int ctr = 0;                // will count the number of nodes deleted 

            //update the node currLeft / i move gikan head hantud ma abot sa left value 
            for(int i = 1; i < left; i++){
                currLeft = currLeft->next;
            }

            //update the node currRight / i move gikan tail padung sa right value
            for(int i = 1; i < right; i++){
                currRight = currRight->prev;
            }

            // para delete sa nodes between currLeft ug currRight
            node *curr = currLeft->next;

            while(curr != currRight){
                slave = curr;
                curr = curr->next;   //updates curr
                free(slave);
                ctr++;
                size--;
            }

            //connect
            currLeft->next = currRight;
            currRight->prev = currLeft;

            //if zero si left pasabot ana kay na delete og apil si head
            if (left == 0) {
                head = currRight;       //set new head
                head->prev = nullptr;
            }

            //if zero si right pasabot ana kay na delete og apil si tail
            if (right == 0) {
                tail = currLeft;        //set new tail
                tail->next = nullptr;
            }

            return ctr;
        }


        void printFromHead(){
            if(head == nullptr|| size == 0){
                cout << "The list is empty" << endl;
                return;
            }

            node* curr = head;
            cout << "FROM HEAD: ";

            while(curr){
                cout << curr->data << " -> ";
                if(curr->next == nullptr){
                    cout << "NULL";
                }
                curr = curr->next;
            }
            cout << endl;
        }


        void printFromTail(){
            if(tail == nullptr || size == 0){
                cout << "The list is empty" << endl;
                return;
            }

            node* curr = tail;

            cout << "FROM TAIL: ";
            while(curr){
                cout << curr->data << " <- ";
                if(curr->prev == nullptr){
                    cout << "NULL";
                }
                curr = curr->prev;
            }
            cout << endl;

        }

        void menu(){
            cout << "---------------------------------------------" << endl;
            cout << "[1] addHead\t[2] addTail\t[3] addAt" << endl;
            cout << "[4] remove\t[5] removeAt\t[6] removeAll" << endl;
            cout << "[7] retain\t[8] corner\t[9] print" << endl;
            cout << "[0] exit" << endl;
            cout << "---------------------------------------------" << endl;
        }
};