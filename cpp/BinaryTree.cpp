#include <iostream>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to create a new node
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Class to implement the binary tree
class BinaryTree {
public:
    Node* root;

    // Constructor to initialize the tree
    BinaryTree() {
        root = nullptr;
    }

    // Function to insert a node in the binary tree
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    // Function for inorder traversal (Left, Root, Right)
    void inorder(Node* node) {
        if (node == nullptr) {
            return;
        }

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Function for preorder traversal (Root, Left, Right)
    void preorder(Node* node) {
        if (node == nullptr) {
            return;
        }

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Function for postorder traversal (Left, Right, Root)
    void postorder(Node* node) {
        if (node == nullptr) {
            return;
        }

        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
};

int main() {
    BinaryTree tree;
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    cout << "Inorder traversal: ";
    tree.inorder(tree.root);
    cout << "\n";

    cout << "Preorder traversal: ";
    tree.preorder(tree.root);
    cout << "\n";

    cout << "Postorder traversal: ";
    tree.postorder(tree.root);
    cout << "\n";

    return 0;
}
