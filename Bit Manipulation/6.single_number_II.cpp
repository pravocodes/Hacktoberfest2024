

//Leetcode - - Single Number II


// Better Solution

// Time complexity - O(nlogn + n/3)
// Space complexity - O(1)

sort(nums.begin(), nums.end());
for(int i=1; i<n; i=i+3){
    if(nums[i] != nums[i-1]){
        return nums[i-1];
    }
}
return nums[n-1];

//Optimal Solution

//Time complexity - O(n)
//Space complexity - O(1)

ones = 0, twos = 0;
for(int i=0; i<n; i++){
    ones = (ones^nums[i]) & twos;
    twos = (twos^nums[i]) & ones;
}
return ones;