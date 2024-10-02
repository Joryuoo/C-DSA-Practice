#include <iostream>
#include <cstdlib>
#include <cmath>
#include "node.h"
#include "list.h"
using namespace std;

class Doubly: public List{
    node *head = nullptr;
    node *tail = nullptr;
    int size = 0;

    public:

    void addHead(int num){
        node *n = (node*) calloc(1, sizeof(node));
        n->elem = num;

        if(head == nullptr && tail == nullptr){
            head = n;
            head->prev = nullptr;
            tail = n;
            tail->next = nullptr;
        } else{
            head->prev = n;
            n->next = head;
            head = n;
            head->prev = nullptr;
        }

        size++;
        return;
    }

    void addTail(int num){
        node *n = (node*) calloc(1, sizeof(node));
        n->elem = num;

        if(tail == nullptr && head == nullptr){
            head = n;
            head->prev = nullptr;
            tail = n;
            tail->next = nullptr;
        } else{
            n->next = nullptr;
            n->prev = tail;
            tail->next = n;
            tail = n;
        }
        size++;
        return;
    }

    void addAt(int pos, int num){
        node *n = (node*) calloc(1, sizeof(node));
        n->elem = num;

        if(pos <= 0 || pos > size + 1){
            cout << "Position not found!" << endl;
            return;
        } else if(pos == 1){
            addHead(num);
        } else if(pos == size + 1){
            addTail(num);
        } else{
            node *curr = head;
            for(int i = 1; i < pos; i++){
                curr = curr->next;
            }

            n->next = curr;
            n->prev = curr->prev;
            curr->prev->next = n;
            curr->prev = n;
            size++;
        }
        return;
    }

    int get(int pos){
        node *curr = nullptr;

        if(pos <= 0 || pos > size+1){
            return -1;
        }

        if(pos <= ceil(size / 2.0)){
            curr = head;
            int ctr = 1;
            while(ctr < pos){
                curr = curr->next;
                ctr++;
            }
            cout << "From head, number of comparisons: " << pos << endl;
        } else{
            curr = tail;
            int ctr = size;
            cout << "From tail, number of comparisons: " << size-pos+1 << endl;
            
            while(ctr > pos){
                curr = curr->prev;
                ctr--;
            }
        }
        return curr->elem;
    }
    
    int remove(int num){
        if(size == 0){
            return -1;
        } 
        if(size == 1){
            free(head);
            head = nullptr;
            tail = nullptr;
            size--;
            return 1;
        } else{
            node *curr = head;
            node *temp = nullptr;
            int ctr = 1;

            while(curr){
                if(curr->elem == num){
                    if(curr == tail && curr->elem == num){
                        temp = curr;
                        curr->prev->next = nullptr;
                        tail = curr->prev;
                        free(temp);
                        size--;
                        return ctr;
                    } else{
                        temp = curr;
                        curr->prev->next = curr->next;
                        curr->next->prev = curr->prev;
                        free(temp);
                        size--;
                        return ctr;
                    }
                }
                curr = curr->next;
                ctr++;
            }
            
        }

        return 0;
    }
    
    int removeAt(int pos){
        if(size == 0){
            return 0;
        }

        if(pos <= 0 || pos > size){
            return -1;
        } 

        node *curr = nullptr;
        node *temp = nullptr;
        int hold = 0;
        
        if(pos == 1 && head->next != nullptr){
            temp = head;
            hold = head->elem;
            head = head->next;
            head->prev = nullptr;
            free(temp);
            size--;
            return hold;
        } else if(pos == 1 && head->next == nullptr){
            temp = head;
            hold = head->elem;
            head = nullptr;
            tail = nullptr;
            free(temp);
            size--;
            return hold;
        }else if(pos == size){
            temp = tail;
            hold = tail->elem;
            tail = tail->prev;
            tail->next = nullptr;
            free(temp);
            size--;
            return hold;
        } else {
            curr = head;
            int ctr = 1;
            while(ctr < pos){
                curr = curr->next;
                ctr++;
            }
            temp = curr;
            hold = curr->elem;
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            free(curr);
            size--;
        }
        return -1;
    }

    int removeAll(int num){
        if(size == 0){
            return -1;
        }

        node *curr = head;
        node *temp = nullptr;
        int removeCount = 0;

        while(curr){
            if(curr->elem == num){
                removeCount++;
                temp = curr;
                if(curr == head && curr == tail){
                    free(head);
                    head = nullptr;
                    tail = nullptr;
                    return removeCount;
                } else if(curr == head && curr->next != nullptr){
                    head = head->next;
                    head->prev = nullptr;
                } else if(curr == tail && curr->prev != nullptr){
                    tail = tail->prev;
                    tail->next = nullptr;
                } else{
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                }
                curr = curr->next;    
                free(temp);
                size--;   
            } else{
                curr = curr->next;
            }
        }
        return removeCount;

    }
    
    int retain(int num){
        if(size == 0){
            return -1;
        }

        node *curr = head;
        node *temp = nullptr;
        int removeCount = 0;

        while(curr){
            if(curr->elem < num){
                temp = curr;
                removeCount++;
                if(curr == head && curr == tail){
                    free(temp);
                    head = nullptr;
                    tail = nullptr;
                    return removeCount;
                } else if(curr == head && curr->next != nullptr){
                    head = head->next;
                    head->prev = nullptr;
                } else if(curr == tail && curr->prev != nullptr){
                    tail = tail->prev;
                    tail->next = nullptr;
                } else{
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                }
                curr = curr->next;
                free(temp);
                size--;
            } else{
                curr = curr->next;
            }
        }
        return removeCount;
    }

    int corner(int left, int right){
        if(size == 0){
            cout << "List is empty" << endl;
            return -1;
        }

        if(left < 0 || left > size || right < 0 || right > size){
            cout << "Invalid corner input" << endl;
            return -1;
        }

        if(left + right >= size || head == tail){
            cout << "No corner can be made." << endl;
            return -1;
        }

        if(left == 0 && right == 0){
            return 0;
        }
        node *leftEnd = head;
        node *rightEnd = tail;
        node *curr = nullptr;
        node *temp = nullptr;
        int removeCount = 0;

        for(int i = 1; i < left; i++){
            leftEnd = leftEnd->next;
        }

        for(int i = 1; i < right; i++){
            rightEnd = rightEnd->prev;
        }
        

        if(left == 0 && right != 0){
            curr = head;
            while(curr!= rightEnd){
                temp = curr;
                curr = curr->next;
                free(temp);
                size--;
                removeCount++;
            }
            head = rightEnd;
            head->prev = nullptr;
            return removeCount;
        } if(right == 0 && left != 0){

            curr = tail;
            while(curr!= leftEnd){
                temp = curr;
                curr = curr->prev;
                free(temp);
                size--;
                removeCount++;
            }

            tail = leftEnd;
            tail->next = nullptr;
            return removeCount;
        } else{
            curr = leftEnd->next;
            while(curr != rightEnd){
                temp = curr;
                curr = curr->next;
                free(temp);
                size--;
                removeCount++;
            }
            leftEnd->next = rightEnd;
            rightEnd->prev = leftEnd;
            return removeCount;
        }

    }

    void fromHead(){
        if(head == nullptr|| size == 0){
            cout << "The list is empty" << endl;
            return;
        }

        node* curr = head;
        cout << "FROM HEAD: ";

        while(curr){
            cout << curr->elem << " -> ";
            if(curr->next == nullptr){
                cout << "NULL";
            }
            curr = curr->next;
        }
        cout << endl;
    }

    void fromTail(){
        if(tail == nullptr || size == 0){
            cout << "The list is empty" << endl;
            return;
        }

        node* curr = tail;

        cout << "FROM TAIL: ";
        while(curr){
            cout << curr->elem << " <- ";
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