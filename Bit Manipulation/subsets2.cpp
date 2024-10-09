class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int>ds;
        vector<vector<int>>ans;

        sort(nums.begin(), nums.end());
        helper(0, ds, ans, nums);

        return ans;
    }

    void helper(int i, vector<int>&ds, vector<vector<int>>&ans, vector<int>&nums){
        
        ans.push_back(ds);
        for(int ind=i; ind<nums.size(); ind++){
            if(ind>i && nums[ind] == nums[ind-1]) continue;

            ds.push_back(nums[ind]);
            helper(ind+1, ds, ans, nums);
            ds.pop_back();
        }

    }
};
