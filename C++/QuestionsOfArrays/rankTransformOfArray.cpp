// Given an array of integers arr, replace each element with its rank.

// The rank represents how large the element is. The rank has the following rules:

// Rank is an integer starting from 1. The larger the element, the larger the rank. If two elements are equal, their rank must be the same. Rank should be as small as possible.

// Input: arr = [40,10,20,30] Output: [4,1,2,3]


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> arrayRankTransform(vector<int>& arr) {
    // Create a sorted copy of the array
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());

    //  Create a map to store ranks
    unordered_map<int, int> rankMap;
    int rank = 1;

    //  Assign ranks to unique elements
    for (int num : sortedArr) {
        if (rankMap.find(num) == rankMap.end()) {
            rankMap[num] = rank++;
        }
    }

    //  Replace each element in the original array with its rank
    for (int& num : arr) {
        num = rankMap[num];
    }

    return arr;
}

int main() {
    vector<int> arr = {40, 10, 20, 30};
    vector<int> rankedArr = arrayRankTransform(arr);

    // Output the ranked array
    for (int rank : rankedArr) {
        cout << rank << " ";
    }
    cout << endl;

    return 0;
}