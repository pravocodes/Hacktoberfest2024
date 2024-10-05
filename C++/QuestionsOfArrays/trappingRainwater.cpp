#include<iostream>
#include<algorithm>
using namespace std;

int trap(int *heights, int n) {
    if (n <= 2) return 0;  

    int left = 0, right = n - 1;
    int leftMax = heights[left], rightMax = heights[right];
    int waterTrapped = 0;

    while (left <= right) {
        if (leftMax < rightMax) {
            leftMax = max(leftMax, heights[left]);   
            waterTrapped += leftMax - heights[left]; r
            left++;
        } else {
            rightMax = max(rightMax, heights[right]); 
            waterTrapped += rightMax - heights[right];
            right--;
        }
    }

    return waterTrapped;
}

int main() {
    int heights[] = {4, 2, 0, 6, 3, 2, 5};
    int n = sizeof(heights) / sizeof(int);

    int result = trap(heights, n);
    cout << "Water trapped: " << result << endl;

    return 0;
}
