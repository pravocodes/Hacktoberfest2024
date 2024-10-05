#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int kadane(const vector<int>& arr) {
    int max_so_far = INT_MIN;
    int max_ending_here = 0;

    for (int i = 0; i < arr.size(); i++) {
        max_ending_here += arr[i];

        if (max_ending_here > max_so_far) {
            max_so_far = max_ending_here;
        }

        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
    }
    return max_so_far;
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum contiguous sum is " << kadane(arr) << endl;
    return 0;
}


// input
// vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};


// output
// Maximum contiguous sum is 6
