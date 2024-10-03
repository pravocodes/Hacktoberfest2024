#include <iostream>
using namespace std;
int main()
{
    int n, arr[n], temp;
    cout << "Enter size: ";
    cin >> n;
    cout << "\nEnter Elements: ";
    for (int i; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "\nAfter sorting: \n";
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        temp = arr[i];
        for (; j >= 0 && arr[j] > temp; j--)
        {
            arr[j+1]=arr[j];
        }
        arr[j+1]=temp;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}