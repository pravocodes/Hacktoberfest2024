#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *left;
    Node *right;
    Node(int ele)
    {
        info = ele;
        left = NULL;
        right = NULL;
    }
};

class Tree
{

public:
    Node *root;
    Tree()
    {
        root = createBT();
    }
    Node *createBT()
    {
        int ele;
        cout<<">";
        cin>>ele;
        if(ele==-1){
            return NULL;
        }
        Node *temp=new Node(ele);
        cout<<"Left of "<<ele<<": ";
        temp->left=createBT();
        cout<<"Right of "<<ele<<": ";
        temp->right=createBT();
    }

    void Inorder(Node *root)
    {
        if (root)
        {
            Inorder(root->left);
            cout << root->info << endl;
            Inorder(root->right);
        }
    }
};

int main()
{
    Tree t;
    t.Inorder(t.root);
}