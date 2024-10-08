#include <iostream>
#include <vector>
#include <map>
#include <limits>  // Include this header for numeric_limits
#include <cmath>
using namespace std;

// Solution class containing the function to find maximum points on a line
class Solution {
public:
    // Function to calculate the maximum number of points on a single line
    int maxPoints(vector<vector<int>>& pt) {
        // If there are less than 2 points, all points are on the same line
        if (pt.size() < 2) return pt.size();
        
        int ans = 1;  // At least one point will always be on the line
        int n = pt.size();  // Number of points in the input array
        
        // Iterate over each point as the base point
        for (int i = 0; i < n - 1; i++) {
            map<double, int> mp;  // A map to store slopes and their frequencies
            for (int j = i + 1; j < n; j++) {
                // Get the coordinates of the points
                double x2 = pt[j][0], x1 = pt[i][0];
                double y2 = pt[j][1], y1 = pt[i][1];
                
                // Handle the case where the points have the same x-coordinate (vertical line)
                double slope;
                if (x2 == x1) {
                    slope = numeric_limits<double>::infinity();  // Vertical line has undefined slope
                } else {
                    slope = (y2 - y1) / (x2 - x1);  // Calculate slope (dy/dx)
                }
                
                // Increment the count of this slope in the map
                mp[slope]++;
            }
            
            // Find the maximum number of points that share the same slope with the base point
            int temp = 0;
            for (auto it : mp) {
                temp = max(temp, it.second);  // Update temp to the maximum frequency of a slope
            }
            
            ans = max(temp + 1, ans);  // Add the base point to the count and update the final answer
        }
        
        return ans;  // Return the maximum number of points on a single line
    }
};

// Helper function to take input points from the user
vector<vector<int>> inputPoints(int n) {
    vector<vector<int>> points(n, vector<int>(2));  // 2D vector to store (x, y) points
    cout << "Enter the points in the format (x, y):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Point " << i + 1 << ": ";
        cin >> points[i][0] >> points[i][1];  // Input x and y coordinates for each point
    }
    return points;
}

int main() {
    int n;
    
    // Input number of points from the user
    cout << "Enter the number of points: ";
    cin >> n;
    
    // If no points or only one point, max points on a line is the number of points
    if (n < 1) {
        cout << "Number of points should be greater than 0." << endl;
        return 0;
    }
    
    // Get the points from the user
    vector<vector<int>> points = inputPoints(n);

    // Create an instance of Solution class and call the maxPoints function
    Solution sol;
    int result = sol.maxPoints(points);

    // Print the result
    cout << "The maximum number of points that lie on the same straight line is: " << result << endl;

    return 0;
}
