#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void countSort(int *arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    int countArray[max + 1] = {0};
    
    for (int i = 0; i < n; i++) {
        countArray[arr[i]]++;
    }
    
    for (int i = 1; i <= max; i++) {
        countArray[i] += countArray[i - 1];
    }
    
    int outputArray[n];
    for (int i = n - 1; i >= 0; i--) {
        outputArray[countArray[arr[i]] - 1] = arr[i];
        countArray[arr[i]]--;
    }
    
    for (int i = 0; i < n; i++) {
        arr[i] = outputArray[i];
    }
}

int main() {
    int arr[10] = {10,3,5,2,8,5,9,3,0,1};
    int n = 10;
    countSort(arr, n);
    printArray(arr, n);
    return 0;
}
