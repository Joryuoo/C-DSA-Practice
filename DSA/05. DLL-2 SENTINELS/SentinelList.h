#include <iostream>
#include <cstdlib>
#include <cmath>
#include "List.h"
using namespace std;

class LinkedList: public List{
    node *head;
    node *tail;
    int size = 0;

    public:
    
    LinkedList(){
        head = (node*) calloc(1, sizeof(node)); //sentinel node /dummy node
        tail = (node*) calloc(1, sizeof(node)); //sent             inel node / dummy node
        head->next = tail;  // This will ensure that we always have a head-
        tail->prev = head;  // and tail
        size = 0;
    }

    // We will use this because we will always have a head and a tail.
    // This means that for the first node, we will need to insert it between the head and the tail.
    void addBetween(int num, node *pred, node *succ){
        node *n = (node*) calloc(1, sizeof(node));
        n->elem = num;
        n->prev = pred;
        n->next = succ;
        pred->next = n;
        succ->prev = n;
        size++;
    }

    void removeNode(node *n){
        node *pred = n->prev;
        node *succ = n->next;
        pred->next = succ;
        succ->prev = pred;
        free(n);
        size--;
    }

    void addHead(int num){
        addBetween(num, head, head->next);
    }

    void addTail(int num){
        addBetween(num, tail->prev, tail);
    }

    void addAt(int pos, int num){
        // check if the position is valid
        if(pos <= 0){
            cout << "Invalid Position!" << endl;
            return;
        }
        if(pos >= size+1){
            addTail(num);
        } else if(pos == 1){
            addHead(num);
        } else{
            node *curr = head->next; // Use head->next because we don't want to access the head itself, as it's a dummy node.
            for(int i = 1; i < pos-1; i++){
                curr = curr->next; // update curr;
            }

            addBetween(num, curr, curr->next);
        }

        return;
    }

    int get(int pos){
        // check if the position is valid
        if(pos > size || pos <= 0){
            return -2; // Invalid position
        }

        // check if there is node other than head and tail
        if(head->next == tail || tail->prev == head){
            return -1; // Empty list
        }

        node *curr = nullptr;
        int holder = 0;
        if(pos <= ceil(size / 2.0)){
            cout << "From Head" << endl;
            curr = head->next;
            for(int i = 1; i < pos; i++){
                curr = curr->next;
            }
            holder = curr->elem;
        } else{
            cout << "From Tail" << endl;
            curr = tail->prev;
            for(int i = size; i > pos; i--){
                curr = curr->prev;
            }
            holder = curr->elem;
        }
        return holder;
    }

    int remove(int num){
        if(head->next == tail){
            return -1;
        }

        node *curr = head->next;
        int posCount = 1;

        while(curr != tail){
            if(curr->elem == num){
                removeNode(curr);
                return posCount;
            }
            curr = curr->next;
            posCount++;
        }
        return 0;
    }

    int removeAt(int pos){
        if(pos > size || pos <= 0){
            return -1;
        }

        node *curr;
        int holder = 0;

        if(pos <= ceil(size / 2.0)){
            cout << "From Head: " << endl;
            curr = head->next;
            for(int i = 1; i < pos; i++){
                curr = curr->next;
            }           
        } else{
            cout << "From Tail: " << endl;
            curr = tail->prev;
            for(int i = size; i > pos; i--){
                curr = curr->prev;
            }
        }

        holder = curr->elem;
        removeNode(curr);
        return holder;
    }

    int removeAll(int num){
        node *curr = head->next;
        int ctr = 0;
        node *temp = nullptr;

        while(curr != tail){
            if(curr->elem == num){
                temp = curr;
                removeNode(temp);
                ctr++;
                curr = curr->next;
            } else{
                curr = curr->next;
            }
        }

        return ctr;
    }

    int retain(int num){
        node *curr = head->next;
        node *temp = nullptr;
        int ctr = 0;

        while(curr != tail){
            if(curr->elem < num){
                temp = curr;
                removeNode(temp);
                ctr++;
                curr = curr->next;
            } else{
                curr = curr->next;
            }
        }

        return ctr;
    }

    int corner(int left, int right) {

        if(left + right >= size || left < 0 || left >= size || right < 0 || right >= size){
            return -1;
        }
        node *leftEnd = nullptr;
        node *rightStart = nullptr;
        node *temp = nullptr;
        int ctr = 0;
        node *curr;

        if(left == 0 && right == 0){
            return 0;
        }

        if(left == 0){
            curr = tail->prev;
            for(int i = 1; i < right; i++){
                curr = curr->prev;
            }
            rightStart = curr;

            curr = head->next; //update curr
            while(curr != rightStart){
                temp = curr;
                removeNode(temp);
                curr = curr->next;
                ctr++;
            }
        } else if(right == 0){
            curr = head->next;
            for(int i = 1; i < left; i++){
                curr = curr->next;
            }
            leftEnd = curr;

            curr = leftEnd->next;
            while(curr != tail){
                temp = curr;
                removeNode(temp);
                curr = curr->next;
                ctr++;
            }
        } else{
            curr = head->next;
            for(int i = 1; i < left; i++){
                curr = curr->next;
            }
            leftEnd = curr;

            curr = tail->prev;
            for(int i = 1; i < right; i++){
                curr = curr->prev;
            }
            rightStart = curr;

            curr = leftEnd->next;

            while(curr != rightStart){
                temp = curr;
                removeNode(temp);
                curr = curr->next;
                ctr++;
            }
        }

        return ctr;
    }

    void fromHead(){
        if(head->next == tail){
            cout << "The list is empty." << endl;
            return;
        }

        node *curr = head->next;
        cout << "From Head: ";;
        while(curr != tail){
            cout << curr->elem << " -> ";
            if(curr->next == tail){
                cout << "Tail";
            }
            curr = curr->next;
        }
        cout << endl;
    }

    void fromTail(){
       if(head->next == tail){
            cout << "The list is empty." << endl;
            return;
        }

        node *curr = tail->prev;
        cout << "From Tail: ";;
        while(curr != head){
            cout << curr->elem << " <- ";
            if(curr->prev == head){
                cout << "Head";
            }
            curr = curr->prev;
        }
        cout << endl;
    
    }
};