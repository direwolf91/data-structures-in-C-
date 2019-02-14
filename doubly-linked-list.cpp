#include<iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node* previous;
};

class DoublyLinkedList{
    Node** head;
    public:
    DoublyLinkedList();
    void insert(int val);
    void printList();
};

DoublyLinkedList::DoublyLinkedList(){
    head = NULL;
}

void DoublyLinkedList::insert(int val){
    Node* newNode = new Node;
    newNode->val = val;
    newNode->previous = NULL;
    newNode->next = NULL;
    if (head == NULL){
        head = &newNode;
    } else {
        newNode->next = *head;
        (*head)->previous = newNode;
        *head = newNode;
    }
}

void DoublyLinkedList::printList(){
    Node** iterator = head;
    while((*iterator)->next != NULL){
        cout << (*iterator)->val;
        *iterator = (*iterator)->next;
    }
}

int main(){
    DoublyLinkedList list;
    list.insert(5);
    list.insert(2);
    list.printList();
}