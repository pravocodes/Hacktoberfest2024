#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *next;
    Node(int ele)
    {
        info = ele;
        next = NULL;
    }
};

Node *insert_list(Node *head, int ele)
{
    Node *temp = new Node(ele);
    if (head == NULL)
    {
        return temp;
    }
    Node *t = head;
    while (t->next != NULL)
    {
        t = t->next;
    }
    t->next = temp;
    return head;
}

void display(Node *head)
{
    if (head == NULL)
    {
        cout << "Empty List";
        return;
    }
    Node *t = head;
    for (; t; t = t->next)
    {
        cout << t->info << "->";
    }
    return;
}

int countnodes(Node *head)
{
    int count = 1;
    if (head == NULL)
    {
        return count-1;
    }
    Node *t = head;
    while (t->next != NULL)
    {
        t = t->next;
        count++;
    }
    return count;
}

Node *sort(Node *head)
{
    int cnt=countnodes(head),temp;
    Node *t = head;
    for (int i = 0; i < (countnodes(head) - 1); i++)
    {
        for (int j = 0; j < (countnodes(head) - i - 1); j++)
        {
            if (t->info > t->next->info)
            {
                temp = t->info;
                t->info = t->next->info;
                t->next->info = temp;
            }
            t = t->next;
        }
        t = head;
    }
    return head;
}

Node *bubblesort(Node *head)
{
    int cnt = countnodes(head), temp;
    Node *t = head;
    for (int i = 0; i < cnt - 1; i++)
    {
        for (int j = 0; j < cnt - i - 1; j++)
        {
            if (t->info > t->next->info)
            {
                temp = t->info;
                t->info = t->next->info;
                t->next->info = temp;
            }
            t = t->next;
        }
        t = head;
    }
    return head;
}

void insert_sort(Node *head,int ele){
        Node *temp=new Node(ele);
        Node *trav=head;
        //EDGE CASE:List Empty
        if(head==NULL){
            head=insert_list(head,ele);
            return;
        }
        if(trav->info>ele){
            temp->next=head;
            head=temp;
            return;
        }
        while(trav->next!=NULL){
            if(trav->next->info>ele){
                temp->next=trav->next;
                trav->next=temp;
                break;
            }
            trav=trav->next;
        }
        if(trav->next==NULL){
            trav->next=temp;
            temp->next=NULL;
        }
}
    

Node *merge(Node *head1, Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    head1=sort(head1);
    Node *t2 = head2;
    while(t2!=NULL){
        insert_sort(head1,t2->info);
        t2=t2->next;
    }
    return head1;
}

int main()
{
    Node *head1 = NULL, *head2 = NULL,*merglist=NULL;
    head1 = insert_list(head1, 100);
    head1 = insert_list(head1, 25);
    head1 = insert_list(head1, 41);
    head1 = insert_list(head1, 76);
    head1 = insert_list(head1, 8);

    head2 = insert_list(head2, 4);
    head2 = insert_list(head2, 32);
    head2 = insert_list(head2, 58);
    head2 = insert_list(head2, 71);
    head2 = insert_list(head2, 10);

    merglist = merge(head1, head2);
    display(sort(merglist));
    
    return 0;
}