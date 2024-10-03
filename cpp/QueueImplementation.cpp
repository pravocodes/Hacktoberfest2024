#include <iostream>
#define MAX 100
using namespace std;
class queue
{
    int r, f;
    int arr[MAX];

public:
    queue()
    {
        r = f = -1;
    }
    void enq(int ele);
    int deq();
    void disp();
    bool IsEmpty();
};

bool queue::IsEmpty()
{
    if (r == f)
    {
        return true;
    }
    return false;
}

void queue::enq(int ele){
    if(r==MAX-1){
        return;
    }
    arr[++r]=ele;
}

int queue::deq(){
    if(IsEmpty()){
        cout<<"Empty Queue";
        return -999;
    }
    return arr[++f];
}

void queue::disp(){
    if(IsEmpty()){
        cout<<"Empty Queue";
        return;
    }
    for(int i=f+1;i<=r;i++){
        cout<<arr[i]<<"  ";
    }
}

int main(){
    queue q;
    int res,ele;
    cout<<"MENU\n1.Enqueue\n2.Dequeue\n3.Display\n\n";
    while(true){
        cout<<"\nEnter your choice: ";
        cin>>res;
        if(res==1){
            cout<<"\nEnter element to enque: ";
            cin>>ele;
            q.enq(ele);
        }  
        else if(res==2){
            cout<<"\nElement dequeued: "<<q.deq();
        }
        else if(res==3){
            q.disp();
        }
        else{
            break;
        }
    }
    return 0;
}