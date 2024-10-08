#include <iostream>
#include <vector>
#include <algorithm>

int kadane(const std::vector<int>& nums) {
    int maxCurrent = nums[0]; // Maximum sum of subarray ending at the current position
    int maxGlobal = nums[0];  // Maximum sum found so far

    for (size_t i = 1; i < nums.size(); ++i) {
        maxCurrent = std::max(nums[i], maxCurrent + nums[i]);
        if (maxCurrent > maxGlobal) {
            maxGlobal = maxCurrent;
        }
    }

    return maxGlobal;
}

int main() {
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int maxSum = kadane(nums);
    std::cout << "Maximum sum of contiguous subarray: " << maxSum << std::endl; // Output: 6
    return 0;
}
