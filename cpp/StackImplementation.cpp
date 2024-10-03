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

int main(){
    stack s;
    int res,ele;
    cout<<"MENU\n1Push\n2.Pop\n3.Display\n\n";
    while(true){
        cout<<"\nEnter your choice: ";
        cin>>res;
        if(res==1){
            cout<<"\nEnter element to push: ";
            cin>>ele;
            s.push(ele);
        }  
        else if(res==2){
            cout<<"\nElement popped: "<<s.pop();
        }
        else if(res==3){
            s.disp();
        }
        else{
            break;
        }
    }
    return 0;
}