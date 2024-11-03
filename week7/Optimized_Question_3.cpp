#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    Solution(vector<int> arr1, vector<int> arr2) {
        // Initialize an unordered_set for the second array for fast lookup
        unordered_set<int> setArr2(arr2.begin(), arr2.end());
        vector<int> uniqueElements;

        // Iterate through the first array and check for elements not in the second array
        for (int num : arr1) {
            if (setArr2.find(num) == setArr2.end()) { // If the element is not found in arr2
                uniqueElements.push_back(num);
            }
        }

        // Store the unique elements in the class instance for retrieval
        this->uniqueElements = uniqueElements;
    }

    vector<int> getUnique() {
        return uniqueElements;
    }

private:
    vector<int> uniqueElements; // To store unique elements found
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 8, 9, 0};
    vector<int> arr2 = {4, 5, 6, 7};
    Solution soln(arr1, arr2);
    vector<int> ans = soln.getUnique();
    for (auto x : ans)
        cout << x << "\t";
    return EXIT_SUCCESS;
}
