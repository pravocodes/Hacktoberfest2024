// C++ program to demonstrate insertion
// in a BST recursively.
#include <iostream>
using namespace std;
 
class BST {
    int data;
    BST *left, *right;
 
public:
 
    // Parameterized constructor.
    BST(int);
 
    // Insert function.
    BST* Insert(BST*, int);
 
    // Inorder traversal.
    void Inorder(BST*);
}; 
// Parameterized Constructor definition.
BST ::BST(int value)
{
    data = value;
    left = right = NULL;
}
 
// Insert function definition.
BST* BST ::Insert(BST* root, int value)
{
    if (!root) {
        return new BST(value);
    }
 
    // Insert data.
    if (value > root->data) {
        root->right = Insert(root->right, value);
    }
    else if (value < root->data){
        root->left = Insert(root->left, value);
    }
    return root;
}
void BST ::Inorder(BST* root)
{
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}
 
// Driver code
int main()
{
    BST b, *root = NULL;
    root = b.Insert(root, 50);
    b.Insert(root, 30);
    b.Insert(root, 20);
    b.Insert(root, 40);
    b.Insert(root, 70);
    b.Insert(root, 60);
    b.Insert(root, 80);
 
    b.Inorder(root);
    return 0;
}