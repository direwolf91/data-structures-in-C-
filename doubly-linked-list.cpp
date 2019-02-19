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
        void insertAfter(int val);
        void insertMiddle(int position, int val);
        void printList();
};

DoublyLinkedList::DoublyLinkedList(){
    head = NULL;
}

void DoublyLinkedList::insertStart(int val){
    Node* newNode = new Node;
    if (!newNode){
        cout << "Memory Error ! \n";
        return;
    }
    newNode->val = val;
    newNode->next = head;
    newNode->previous = NULL;
    if (head != NULL){
        head->previous = newNode;
    }
    head = newNode;
}

void DoublyLinkedList::insertAfter(int val){
    Node* newNode = new Node;
    if (!newNode){
        cout << "Memory Error ! \n";
        return;
    }
    newNode->val = val;
    if (head == NULL){
        head = newNode;
        newNode->previous = NULL;
        newNode->next = NULL;
    }else {
        Node* temp = head;
        while(temp->next != NULL)temp=temp->next;
        temp->next = newNode;
        newNode->previous = temp;
        newNode->next = NULL;
    }
}

void DoublyLinkedList::insertMiddle(int position, int val){
    if (head == NULL){
        cout << "Empty list \n";
        return;
    }
    Node *temp = head;
    int current_pos = 1;
    if (position == 1){
        Node* newNode = new Node;
        newNode->val = val;
        newNode->next = head;
        newNode->previous = NULL;
        head = newNode;
        return;
    }
    while(temp->next != NULL && position - 1 >current_pos){
        temp=temp->next;
        current_pos++;
    }
    if (current_pos != position - 1){
        cout << "Position greater than list length \n";
        return;
    }
    Node* newNode = new Node;
    newNode->val = val;
    newNode->next= NULL;
    if (temp->next != NULL){
        newNode->next = temp->next;
        temp->next->previous = newNode;
    }
    newNode->previous = temp;
    temp->next = newNode;
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
    list.insertAfter(10);
    list.insertMiddle(3, 13);
    list.printList();
}