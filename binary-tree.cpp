#include<iostream>
#include<stack>
using namespace std;

struct Node{
    int data;
    Node* right_child;
    Node* left_child;
};

class BinaryTree{
    Node* root;
    public: 
        BinaryTree(){
            root = NULL;
        }
      //Operations in a Binary Tree
      //1. Get Node
      Node* GetNode();
      //2. Insert a node
      void InsertNode(Node*);
      //3. Delete a node
      void DeleteNode(Node*);
      //4.1. Inorder traversal
      void InOrder(Node*);
      //4.2. Preorder traversal
      void PreOrder(Node*);
      //4.3 Postorder traversal
      void Postorder(Node*); 

      Node *TreeCopy();
      void Mirror();
      int TreeHeight(Node*);
      int CountLeaf(Node*);
      int CountNode(Node*);
      void BFS_Tree();
      void DFS_Tree();
      void Postorder_Non_Recursive();
      void Inorder_Non_Recursive(Node*);
      void Preorder_Non_Recursive(Node*);
      int BTree_Equal(BinaryTree, BinaryTree);
      Node *TreeCopy(Node*);
      void Mirror(Node*);
};

//Binary tree traversal
void BinaryTree::PreOrder(Node* treeNode){
    if(treeNode != NULL){
        cout << treeNode->data;
        PreOrder(treeNode->left_child);
        PreOrder(treeNode->right_child);
    }    
}

void BinaryTree::InOrder(Node* treeNode){
    if(treeNode != NULL){ 
        PreOrder(treeNode->left_child);
        cout << treeNode->data;
        PreOrder(treeNode->right_child);
    }    
}

void BinaryTree::Postorder(Node* treeNode){
    if(treeNode != NULL){
        PreOrder(treeNode->left_child);
        PreOrder(treeNode->right_child);
        cout << treeNode->data;
    }    
}

void BinaryTree::Inorder_Non_Recursive(Node* root){
    stack<Node*> s;
    Node* current = root;
    while(current!=NULL || s.empty() == false){
        while(current != NULL){
            s.push(current);
            current = current->left_child;
        }

        current = s.top();
        s.pop();

        cout << current->data;
        current = current->right_child;
    }
}

void BinaryTree::Preorder_Non_Recursive(Node* root){
    stack<Node*> s;
    Node* current = root;
    while(current!=NULL || s.empty() == false){
        while(current != NULL){
            cout << current->data;
            s.push(current);
            current = current->left_child;
        }

        current = s.top();
        s.pop();

        current = current->right_child;
    }
}


int main(){
    return 0;
}