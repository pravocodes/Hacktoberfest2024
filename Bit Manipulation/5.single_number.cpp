

//Leetcode - 136 - Single Number

// Time complexity: O(n)
// Space complexity: O(1)

int singleNumber(vector<int> &nums)
{
    int xorr = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        xorr = xorr ^ nums[i];
    }
    return xorr;
}