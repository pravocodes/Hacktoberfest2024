#include <iostream>
using namespace std;

class Node{
    public:
    int info;
    Node *next;
    Node(int ele){
        info=ele;
        next=NULL;
    }
};

Node* insert_list(Node* head,int ele){
    Node *temp=new Node(ele);
    if(head==NULL){
        return temp;
    }
    Node *t=head;
    while(t->next!=NULL){
        t=t->next;
    }
    t->next=temp;
    return head;
}

Node *display(Node *head){
    if(head==NULL){
        cout<<"Empty List";
        return head;
    }
    Node *t=head;
    for(;t;t=t->next){
        cout<<t->info<<"->";
    }
}

Node *reversekalternate(Node *head,int k){
    int count=0;
    if(head==NULL){
        return head;
    }
    Node *cur=head,*prev=NULL,*nextptr=NULL;
    while(cur && count<k){
        nextptr=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nextptr;
        count++;
    }
    if(nextptr != NULL){
        head->next=reversekalternate(nextptr,k);
    }
    return prev;
}

int main(){
    Node *head=NULL,*alt=NULL,*temp=NULL;
    int ele,res;
    head=insert_list(head,1);
    head=insert_list(head,2);
    head=insert_list(head,3);
    head=insert_list(head,4);
    head=insert_list(head,5);
    head=insert_list(head,6);
    head=insert_list(head,7);
    head=insert_list(head,8);
    cout<<endl;
    display(head);
    cout<<endl;
    head=reversekalternate(head,3);
    display(head);
    // cout<<"MENU\n1.Insert\n2.Display\n3.Alternate-K-Nodes\n\n";
    // while(true){
    //     cout<<"\nEnter your choice: ";
    //     cin>>res;
    //     if(res==1){
    //         cout<<"Enter element: ";
    //         cin>>ele;
    //         head=insert_list(head,ele);
    //     }  
    //     else if(res==2){
    //         display(head);
    //     }
    //     else if(res==3){
    //         // s.disp();
    //     }
    //     else{
    //         break;
    //     }
    // }
}