#include<iostream>
using namespace std;
void print(int *arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
void Selection(int *arr, int n){
    for(int i=0; i<n-1; i++){
        int minIdx = i;
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[minIdx]){
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
    print(arr,n);
}
int main(){
int arr[7] = {9,8,5,6,4,8,3};
int n = sizeof(arr)/sizeof(int);
Selection(arr, n);
}