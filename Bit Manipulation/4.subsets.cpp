


// Leetcode 78 - Subsets
// Find all subsets of given array
// Time complexity: O(2^n * n)
// Space complexity: O(2^n * n)

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    int numSubsets = 1 << n;  // Total number of subsets is 2^n
    vector<vector<int>> ans;

    for (int num = 0; num < numSubsets; num++) {
        vector<int> list;
        for (int i = 0; i < n; i++) {
            if (num & (1 << i)) {
                list.push_back(nums[i]);
            }
        }
        ans.push_back(list);
    }
    return ans;
}
