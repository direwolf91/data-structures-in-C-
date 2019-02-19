#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

class CircularLinkedList{
    Node* head;
    public:
        CircularLinkedList();
        void insert(int val);
        void printlist();
};

CircularLinkedList::CircularLinkedList(){
    head = NULL;
}

void CircularLinkedList::insert(int val){
    Node* newNode = new Node();
    if (!newNode){
        cout<< "Memory issue \n";
        return;
    }
    newNode->data = val;
    newNode->next = newNode;
    if (head == NULL){
        head = newNode;
    } else {
        newNode->next = head;
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void CircularLinkedList::printlist(){
    Node* temp = head;
    if (head == NULL){
        return;
    }else if(head->next == head){
        cout << head->data;
        return;
    }
    while(temp->next != head){
        cout << temp->data;
        temp = temp->next;
    }
    cout << temp->data;
}

int main(){
    CircularLinkedList list;
    list.insert(5);
    list.insert(3);
    list.insert(10);
    list.printlist();
    return 0;
}