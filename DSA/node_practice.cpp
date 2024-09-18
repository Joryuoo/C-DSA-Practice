#include <iostream>
#include <cstdlib>
using namespace std;

struct Node{
    int elem;
    Node * next; //self referential structure
};

int main(){
    //Learning the hard way XD
    Node * head, * tail;
    int data;

    head = (Node*) malloc(sizeof(Node));

    cout << "Enter element: ";
    cin >> data;

    head->elem = data;
    head->next = nullptr;

    cout << "Address of the first node is: " << head << endl;
    cout << "Element of the first node is: " << head->elem << endl;
    cout << "Address of the next node is: " << head->next << endl << endl;

    tail = (Node*) malloc(sizeof(Node));

    cout << "Enter element: ";
    cin >> data;

    tail->elem = data;
    tail->next = nullptr;

    head->next = tail;

    cout << "Address of the second node is: " << tail << endl;
    cout << "Element of the second node is: " << tail->elem << endl;
    cout << "Address of the next node is: " << tail->next << endl;

    cout << "\nThe first node is now pointing to: " << head->next << endl << endl;

    ///////////////////////////////////////////////////////////////

    tail = (Node*) malloc(sizeof(Node));

    cout << "Enter element: ";
    cin >> data;

    tail->elem = data;
    tail->next = nullptr;
    
    head->next->next = tail;

    cout << "Address of the third node is: " << tail << endl;
    cout << "Element of the third node is: " << tail->elem << endl;
    cout << "Address of the next node is: " << tail->next << endl;

    cout << "\nThe second node is now pointing to: " << head->next->next << endl << endl;

    ///////////////////////////////////////////////////////////////

    tail = (Node*) malloc(sizeof(Node));

    cout << "Enter element: ";
    cin >> data;

    tail->elem = data;
    tail->next = nullptr;
    
    head->next->next->next = tail;

    cout << "Address of the fourth node is: " << tail << endl;
    cout << "Element of the fourth node is: " << tail->elem << endl;
    cout << "Address of the next node is: " << tail->next << endl;

    cout << "\nThe third node is now pointing to: " << head->next->next << endl << endl;

    ///////////////////////////////////////////////////////////////

     tail = (Node*) malloc(sizeof(Node));

    cout << "Enter element: ";
    cin >> data;

    tail->elem = data;
    tail->next = nullptr;
    
    head->next->next->next->next = tail;

    cout << "Address of the fourth node is: " << tail << endl;
    cout << "Element of the fourth node is: " << tail->elem << endl;
    cout << "Address of the next node is: " << tail->next << endl;

    cout << "\nThe third node is now pointing to: " << head->next->next << endl << endl;

    ///////////////////////////////////////////////////////////////

    cout << "Address of the first node is: " << head << endl;
    cout << "Element of the first node is: " << head->elem << endl;
    cout << "Address of the next node is: " << head->next << endl << endl;

    cout << "Address of the second node is: " << head->next << endl;
    cout << "Element of the second node is: " << head->next->elem << endl;
    cout << "Address of the next node is: " << head->next->next << endl << endl; 

    cout << "Address of the third node is: " << head->next->next << endl;
    cout << "Element of the third node is: " << head->next->next->elem << endl;
    cout << "Address of the next node is: " << head->next->next->next << endl << endl; 

    cout << "Address of the fourth node is: " << head->next->next->next << endl;
    cout << "Element of the fourth node is: " << head->next->next->next->elem << endl;
    cout << "Address of the next node is: " << head->next->next->next->next << endl << endl; 

    cout << "Address of the fifth node is: " << head->next->next->next->next << endl;
    cout << "Element of the fifth node is: " << head->next->next->next->next->elem << endl;
    cout << "Address of the next node is: " << head->next->next->next->next->next << endl << endl;
 
}