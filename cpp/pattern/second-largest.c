#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int secondLargest(int arr[], int n) {
    if (n < 2) return -1;  // size is not enough
    // final result
    for (int i = n-2; i >= 0; i--) {
        if (arr[i] != arr[n-1]) {
            return arr[i];
        }
    }
    return -1; 
}

int main() {
    int arr[] = {12, 35, 10000, 1, 34, 10000};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    int result = secondLargest(arr, n);
    
    if (result == -1) {
        printf("There is no second largest element\n");
    } else {
        printf("The second largest element is %d\n", result);
    }
    
    return 0;
}





// #include <stdio.h>
// #include <limits.h>

// int findSecondLargest(int arr[], int size) {
//     if (size < 2) {
//         printf("Array should have at least two elements.\n");
//         return INT_MIN; 
//     }

//     int firstLargest, secondLargest;
//     firstLargest = secondLargest = INT_MIN;

//     for (int i = 0; i < size; i++) {
//         if (arr[i] > firstLargest) {
//             secondLargest = firstLargest;
//             firstLargest = arr[i];
//         } else if (arr[i] > secondLargest && arr[i] != firstLargest) {
//             secondLargest = arr[i];
//         }
//     }

//     if (secondLargest == INT_MIN) {
//         printf("There is no second largest element.\n");
//         return INT_MIN;
//     }

//     return secondLargest;
// }

// int main() {
//     int arr[] = {12, 35, 1, 10, 34, 100};
//     int size = sizeof(arr) / sizeof(arr[0]);

//     int secondLargest = findSecondLargest(arr, size);

//     if (secondLargest != INT_MIN) {
//         printf("The second largest element is %d\n", secondLargest);
//     }

//     return 0;
// }
