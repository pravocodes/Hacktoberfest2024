#include <iostream>
#define MAX 100
using namespace std;

class que{
public:
    int f;
    int r;
    int arr[MAX];
    que(){
    f=-1;
    r=-1;
    }
    void enq(int);
    int deq();
    void display();
    bool IsEmpty();
};

void que::enq(int ele){
    if (r==MAX-1){
        cout<<"Queue is full...";
    }
    arr[++r]=ele;
}

int que::deq(){
    if (f==r){
        cout<<"Queue if empty...";
        return -999;
    }
    return arr[++f];
}

bool que::IsEmpty(){
    if (f==r){
        return true;
    }
    return false;
}

class stk{
    que q1,q2;
    public:
    void push(int ele);
    int pop();
    void disp();
};

void stk::push(int ele){
    q1.enq(ele);
}

int stk::pop(){
    while(q1.f!=(q1.r-1)){
        q2.enq(q1.deq());
    }
    int ele=q1.deq();
    while(q2.f!=(q2.r)){
        q1.enq(q2.deq());
    }
    return ele;
}

void stk::disp(){
    for(int i=q1.f+1;i<=q1.r;i++){
        cout<<q1.arr[i]<<"  ";
    }
}

int main(){
    stk s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    s.disp();
    return 0;
}