// An array A[] of n numbers and another number x is given to you. Write a program to
// check whether or not there exist two elements in A[] whose sum is exactly x.
#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> TwoSum(vector<int> arr, int target)
    {
        unordered_map<int, int> table;
        for (int i = 0; i < arr.size(); i++)
        {
            int complement = target - arr[i];
            if (table.find(complement) != table.end())
            {
                // Return the index of the complement and the current index
                return vector<int>{table[complement], i};
            }
            // Insert the current element with its index into the map
            table[arr[i]] = i;
        }
        return vector<int>{-1, -1}; // Return {-1, -1} if no solution is found
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> arr = {2, 7, 11, 15};
    Solution soln;

    // Test case where the target is found
    vector<int> ans = soln.TwoSum(arr, 9);
    if (ans[0] != -1)
        cout << ans[0] << '\t' << ans[1] << endl; // Expected output: 0   1
    else
        cout << "No solution found" << endl;

    // Test case where the target is not found
    ans = soln.TwoSum(arr, -1);
    if (ans[0] != -1)
        cout << ans[0] << '\t' << ans[1] << endl;
    else
        cout << "No solution found" << endl;

    return EXIT_SUCCESS;
}
