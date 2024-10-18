#include <bits/stdc++.h>
using namespace std;
void InsertionSort(int arr[],int n){
    for(int i=0;i<=n-1;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}
int main(){
    int n;
    cout<<"Enter size of the array"<<endl;
    cin>>n;
    cout<<"Enter Unsorted Array"<<endl;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    InsertionSort(arr,n);
    cout<<"Sorted Array :"<<endl;
    for(int i=0;i<=n-1;i++){
        cout<<arr[i]<<" ";
    }
}