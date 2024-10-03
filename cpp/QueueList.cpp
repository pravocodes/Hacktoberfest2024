#include<iostream> 
#include<cmath>
#include<cstring> 
#include<vector> 
using namespace std; 

class Node{
    public:
    Node* next;
    int data;
    Node(int info){
        data=info;
        next=NULL;
    }
};

class Que{
    Node *front=NULL;
    Node *rear=NULL;
    public:
    void Enque(int x){
        Node* newNode=new Node(x);
        if(rear == NULL){
            rear=newNode;
            front=newNode;
            return;
        }
        rear->next=newNode;
        rear=newNode;
        return;
    }
    int Deque(){
        if(rear == NULL){
            cout<<"Queue is Empty"<<endl;
            return -9999;
        }
        Node* t=front;
        int ans=front->data;
        front=front->next;
        delete t;
        return ans;
    }
    void display(){
        Node* temp=front;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Que q1; 
    for(int i=0;i<5;i++){
        q1.Enque(5*i);
    }
    q1.display();
    q1.Deque();
    q1.Deque();
    q1.Deque();
    q1.Deque();
    q1.display();
    q1.Enque(77);
    q1.display();
    return 0;
}