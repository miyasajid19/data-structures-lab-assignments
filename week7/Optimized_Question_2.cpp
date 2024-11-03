#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find two indices such that their values sum to the target
    vector<int> TwoSum(const vector<int>& arr, int target) {
        unordered_map<int, int> table; // Map to store number and its index
        for (int i = 0; i < arr.size(); i++) {
            // Calculate the complement needed to reach the target
            int complement = target - arr[i];
            // Check if the complement exists in the map
            if (table.find(complement) != table.end()) {
                return {table[complement], i}; // Return the indices
            }
            // Store the current number and its index
            table[arr[i]] = i;
        }
        return {-1, -1}; // Return {-1, -1} if no solution is found
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> arr = {2, 7, 11, 15};
    Solution soln;

    // Test case where the target is found
    vector<int> ans = soln.TwoSum(arr, 9);
    if (ans[0] != -1) {
        cout << ans[0] << '\t' << ans[1] << endl; // Expected output: 0   1
    } else {
        cout << "No solution found" << endl;
    }

    // Test case where the target is not found
    ans = soln.TwoSum(arr, -1);
    if (ans[0] != -1) {
        cout << ans[0] << '\t' << ans[1] << endl;
    } else {
        cout << "No solution found" << endl;
    }

    return EXIT_SUCCESS;
}
