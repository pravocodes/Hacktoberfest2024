#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/**
 * @brief Function to find the maximum sum of a contiguous subarray using Kadane's Algorithm.
 * @param arr The input vector of integers.
 * @return The maximum contiguous subarray sum.
 */
int kadane(const vector<int>& arr) {
    int max_so_far = INT_MIN; // Stores the maximum sum found so far
    int max_ending_here = 0;   // Stores the current subarray sum

    for (int i = 0; i < arr.size(); i++) {
        max_ending_here += arr[i]; // Add the current element to the current subarray sum

        // Update max_so_far if max_ending_here is greater
        if (max_ending_here > max_so_far) {
            max_so_far = max_ending_here;
        }

        // Reset max_ending_here to 0 if it becomes negative
        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
    }
    return max_so_far;
}

/**
 * @brief Main function to test the Kadane's algorithm implementation.
 * @return 0 on successful execution.
 */
int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum contiguous sum is " << kadane(arr) << endl;
    return 0;
}
