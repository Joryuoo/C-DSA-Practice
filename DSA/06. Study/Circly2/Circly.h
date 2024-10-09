#include <iostream>
using namespace std;

struct node{
    int elem;
    node *next;
};
class Circly{
    node *tail;
    public:
    Circly(){
        tail = nullptr;
    }

    void add(int num){
        node *n = new node();
        n->elem = num;

        if(!tail){
            tail = n;
            tail->next = n;
        } else{
            n->next = tail->next;
            tail->next = n;
            tail = n;
        }
    }

    void removeFirst(){
        if(tail == nullptr){
            cout << "Your list is empty" << endl;
        } else if(tail == tail->next){
            cout << "Removing " << tail->elem <<"..." << endl;
            tail = nullptr;
        } else{
            cout << "Removing " << tail->next->elem <<"..." << endl;
            node *temp = tail->next;
            tail->next = tail->next->next;
            delete(temp);
        }
    }

    void remove(int num){
        if(tail == nullptr){
            cout << "Your list is empty" << endl;
        } else if(tail == tail->next && tail->elem == num){
            cout << "List is now empty" << endl;
            tail = nullptr;
        }else if(tail!= nullptr){
            cout << "Removing " << num << "..." << endl;
            node *curr = tail->next;
            node *pred = nullptr;
            bool found = false;

            do{
                if(curr->elem == num){
                    found = true;
                    node *temp = curr;

                    if(curr == tail){ //if tail
                        pred->next = tail->next;
                        tail = pred;
                    } else if(curr == tail->next){ //if head
                        tail->next = curr->next;
                    } else if(curr == tail && curr == tail->next){ //wa niy labot kay di mugana XD
                        cout << "List is now empty" << endl;
                        tail = nullptr;
                        
                    } else{
                        pred->next = curr->next;
                    }

                    delete(temp);
                    break;
                }
                pred = curr;
                curr = curr->next;
            }while(curr != tail->next);

            if(!found){
                cout << "Element not found" << endl;
            }
        }
    }

    void print(){
        if(tail == nullptr){
            cout << "List is empty" << endl;
            return;
        }

        node *curr = tail->next;

        do{
            if(curr->next == tail->next){
                cout << curr->elem;
            } else{
                cout << curr->elem << " -> ";
            }
            curr = curr->next;
        }while(curr != tail->next);
        cout << " | Tail = " << tail->elem << " | Tail->next = " << tail->next->elem << " |" << endl;
    }
};