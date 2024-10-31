#include <iostream>
#include <vector>
#include <algorithm>

int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is at mid
        if (arr[mid] == target) {
            return mid; // Target found at index mid
        }
        
        // If target is greater, ignore left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }

    return -1; // Target not found
}

int main() {
    int n, target;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "Enter the target value to search: ";
    std::cin >> target;

    int result = binarySearch(arr, target);
    
    if (result != -1) {
        std::cout << "Target found at index " << result << ".\n";
    } else {
        std::cout << "Target not found in the array.\n";
    }

    return 0;
}
