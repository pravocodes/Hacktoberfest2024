#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    // Insert a new node
    void insert(int value) {
        root = insertRec(root, value);
    }

    // In-order traversal of the tree
    void inOrderTraversal() {
        inOrderRec(root);
        std::cout << std::endl;
    }

    // Delete the tree
    void deleteTree() {
        deleteRec(root);
        root = nullptr;
    }

private:
    // Helper function to insert a node
    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else {
            node->right = insertRec(node->right, value);
        }
        return node;
    }

    // Helper function for in-order traversal
    void inOrderRec(Node* node) {
        if (node != nullptr) {
            inOrderRec(node->left);
            std::cout << node->data << " ";
            inOrderRec(node->right);
        }
    }

    // Helper function to delete the tree
    void deleteRec(Node* node) {
        if (node != nullptr) {
            deleteRec(node->left);
            deleteRec(node->right);
            delete node;
        }
    }
};

int main() {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    std::cout << "In-order Traversal: ";
    tree.inOrderTraversal();

    tree.deleteTree();
    std::cout << "Tree deleted." << std::endl;

    return 0;
}
