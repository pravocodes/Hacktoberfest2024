// In this program we will perform Preorder traversal on a binary tree

#include <iostream>
using namespace std;

class Node{
public:
  int val;
  Node* left;
  Node* right;

  Node (int data){
    val = data;
    left = NULL;
    right = NULL;
  }
};

Node* BuildTree(Node* &root){

  int data;
  cout<<"Enter data:- ";
  cin>> data;

  root = new Node (data);

  if (data == -1) return NULL;

  cout<<"Enter data in left of "<<data<<endl;
  root->left = BuildTree(root->left);

  cout<<"Enter data in right of "<<data<<endl;
  root->right = BuildTree(root->right);

  return root;

}

void Preorder(Node* &root){
  
  if (root == NULL) return;
  
  cout<<root->val<<" ";
  
  Preorder(root->left);
  Preorder(root->right);
  
}

int main() {
  Node* root = NULL;
  BuildTree(root);
  cout<<"Preorder Traversal:-";
  Preorder(root);
}
