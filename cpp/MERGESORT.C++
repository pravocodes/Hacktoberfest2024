#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr1,vector<int>&arr2,vector<int> &res){

    int i=0;
    int j=0;
    int k=0;
    while (i<arr1.size() && j<arr2.size())
    {
        if(arr1[i]<arr2[j]){
           res[k]=arr1[i];
           i++;
           k++;
        }
      else{
           res[k]=arr2[j];
           j++;
           k++;
        }
    }
    if(i==arr1.size()){
  while(j<arr2.size()){
         res[k]=arr2[j];
        j++;
        k++;
    }
    }
   if(j==arr2.size()){
  while(i<arr1.size()){
        res[k]=arr1[i];
        i++;
        k++;
    }
   }

}

void merge_sort(vector<int>&v){
    if(v.size()==1){
        return;
    }
    int n=v.size();
    int n1=n/2;
    int n2=n-n/2;
    vector<int>a(n1);
     vector<int>b(n2);
    for (int i = 0; i < n1; i++)
    {
        a[i]=v[i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i]=v[i+n1];
    }
    

    merge_sort(a);
    merge_sort(b);
    merge(a,b,v);


}

int main(){
   /*int arr1[]={1,3,5,7,9};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int arr2[]={2,4,6,8,10};
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    
    vector<int>a(arr1,arr1+n1);
      vector<int>b(arr2,arr2+n2);
      vector<int>res(n1+n2);*/
  //  merge(a,b,res);
  int n;
  cout<<"enter size of array";
  cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  merge_sort(v);
for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
}
}
