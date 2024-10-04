#include<iostream>
using namespace std;
void printArray(int arr[], int n){
for(int i = 0; i<n; i++){
    cout<<arr[i]<<" ";
}
}
void insertionSort(int arr[], int n){
    for(int i = 1; i<n; i++){
        int curr  = arr[i];
        int prev = i-1;
        while(prev>=0 && arr[prev]>curr){
            swap(arr[prev], arr[prev+1]);
            prev--;
        }
        arr[prev+1] = curr;
    }
    printArray(arr,n);
    
}
int main(){
int n;
cout<<"Enter number of elements"<<endl;
cin>>n;
int arr[n];
cout<<"enter array elements"<<endl;
for(int i = 0; i<n; i++){
    cin>>arr[i];
}
insertionSort(arr,n);

}