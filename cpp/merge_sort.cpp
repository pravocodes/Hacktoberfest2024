#include <iostream>
#include <cstdlib>
 
using namespace std;
 
struct Node
{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;
 
void create(int A[], int n)
{
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    
    for(int i=1;i<n;i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
 
void create2(int A[], int n)
{
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;
    
    for(int i=1;i<n;i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
 
void display(struct Node *p)
{
    if(p != NULL)
    {
        cout << p->data << " ";
        display(p->next);
    }
}
 
int counting(struct Node *p)
{
    int total {0};
    while(p != 0)
    {
        total++;
        p = p->next;
    }
    return total;
}
 
void concatenate(struct Node *p, struct Node *q)
{
    third = p;
    
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}
 
void merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    
    if(p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if(p)last->next=p;
    if(q)last->next=q;
}
 
int main()
{
    int A[] = {2,4,6,8,10,12};

int B[] = {10,20,30,40,50,60};

int sizeA, sizeB;

sizeA = sizeof(A)/sizeof(A[0]);

sizeB = sizeof(B)/sizeof(B[0]);

create(A,sizeA);

create2(B,sizeB);

display(first);

cout << endl;

display(second);

cout << endl;

// concatenate(first,second);

// display(third);

// cout << endl;

merge(first,second);

display(third);

return 0;
}
