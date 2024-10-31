/*
 * C++ Program to Implement Merge Sort with Dynamic Memory Allocation
 */

#include <iostream>

using namespace std;

// A function to merge the two halves into sorted data.
void Merge(int *a, int low, int high, int mid)
{
    // We have low to mid and mid+1 to high already sorted.
    int i, j, k;
    int *temp = new int[high - low + 1]; // dynamically allocate temp array
    i = low;
    k = 0;
    j = mid + 1;

    // Merge the two parts into temp[].
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
        }
    }

    // Insert all the remaining values from i to mid into temp[].
    while (i <= mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }

    // Insert all the remaining values from j to high into temp[].
    while (j <= high)
    {
        temp[k] = a[j];
        k++;
        j++;
    }

    // Assign sorted data stored in temp[] to a[].
    for (i = low; i <= high; i++)
    {
        a[i] = temp[i - low];
    }

    delete[] temp; // deallocate the dynamically allocated temp array
}

// A function to split the array into two parts.
void MergeSort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        // Split the data into two halves.
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);

        // Merge them to get sorted output.
        Merge(a, low, high, mid);
    }
}

int main()
{
    int n, i;
    cout << "\nEnter the number of data elements to be sorted: ";
    cin >> n;

    // Dynamically allocate memory for the array
    int *arr = new int[n];

    for (i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    MergeSort(arr, 0, n - 1);

    // Printing the sorted data.
    cout << "\nSorted Data ";
    for (i = 0; i < n; i++)
        cout << " -> " << arr[i];

    // Deallocate the dynamically allocated memory for the array
    delete[] arr;

    return 0;
}
