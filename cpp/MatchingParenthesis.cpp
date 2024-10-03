#include <iostream>
#define MAX 100
using namespace std;
class stack
{
    int top;
    int arr[MAX];

public:
    stack()
    {
        top= -1;
    }
    void push(int ele);
    int pop();
    void disp();
    bool IsEmpty();
    void parenthesischeck();
};

bool stack::IsEmpty()
{
    if (top==-1)
    {
        return true;
    }
    return false;
}

void stack::push(int ele){
    if(top==MAX-1){
        return;
    }
    arr[++top]=ele;
}

int stack::pop(){
    if(IsEmpty()){
        cout<<"Empty stack";
        return -999;
    }
    return arr[top--];
}

void stack::disp(){
    if(IsEmpty()){
        cout<<"Empty stack";
        return;
    }
    for(int i=top;i!=-1;i--){
        cout<<arr[i]<<"  ";
    }
}

void stack::parenthesischeck(){
    cout<<"Enter Expression: ";
}

int main(){
    
    return 0;
}