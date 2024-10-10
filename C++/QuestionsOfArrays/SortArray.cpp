
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    // Initializing an array
    int arr[] = { 5, 4, 1, 2, 3 };

    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print the array before sorting the elements
    cout << "Array Before Sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort the array
    sort(arr, arr + n);

    // Print the array after sorting the elements
    cout << "Array After Sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
