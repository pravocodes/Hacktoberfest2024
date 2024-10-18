#include<bits/stdc++.h>
using namespace std;
void merge(int *arr,int l,int mid,int r){
    int ans[r-l+1];
    int i = l, j = mid+1;
    int k = 0;
    while(i<=mid && j<=r){
        if(arr[i] < arr[j]){
            ans[k++] = arr[i++];
        }else{
            ans[k++] = arr[j++];
        }
    }
    while(i<=mid){
        ans[k++] = arr[i++];
    }
    while(j<=r){
        ans[k++] = arr[i++];
    }
    for(int i = 0;i<k;i++){
        arr[i+l] = ans[i];
    }
}
void mergeSort(int *arr,int l,int r){
    if(l>=r){
        return;
    }
    int mid = l+(r-l)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
}
int main(){
    int arr[] = {0,6,0,3,2};
    int n= 5;
    mergeSort(arr,0,n-1);
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
