#include<iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node* previous;
};

class DoublyLinkedList{
    Node* head;
    public:
    DoublyLinkedList();
    void insertStart(int val);
    void printList();
};

DoublyLinkedList::DoublyLinkedList(){
    head = NULL;
}

void DoublyLinkedList::insertStart(int val){
    Node* newNode = new Node;
    newNode->val = val;
    newNode->next = head;
    newNode->previous = NULL;
    if (head != NULL){
        head->previous = newNode;
    }
    head = newNode;
}

void DoublyLinkedList::printList(){
  Node* temp = head;
  while(temp != NULL){
      cout << temp->val << " --> ";
      temp = temp->next;
  }
  cout << "NULL \n";
}

int main(){
    DoublyLinkedList list;
    list.insertStart(5);
    list.insertStart(2);
    list.printList();
}