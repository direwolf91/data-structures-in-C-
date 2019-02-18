#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class LinkedList{
    Node* head;
    public:
    LinkedList();
    void insert(int);
    void insertEnd(int);
    void insertMiddle(int); //Insert at a given position. Assuming the length of linked list is more than the position
    void printList();
};

LinkedList::LinkedList(){
    head = NULL;
}

void LinkedList::insert(int val){
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL){
        head = newNode;
    }else {
        newNode->next = head;
        head = newNode;
        cout << "New Node inserted successfully! \n";
    }
}

void LinkedList::insertEnd(int val){
    Node* temp = head;
    if (head == NULL){
        head = new Node();
        head->data = val;
        head->next = NULL;
    }else{
        while(temp->next != NULL){
             temp = temp->next;
        };
    }
    temp->next = new Node();
    temp->next->data = val;
    temp->next->next = NULL;
}

void LinkedList::printList(){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " --> ";
        temp = temp->next;
    }
    cout << "Null\n";
}

int main(){
    LinkedList list;
    list.insert(5);
    list.insert(10);
    list.insertEnd(15);
    list.printList();
    return 0;
}