// You are provided with two arrays. Write a program to find numbers which are present
// in first array, but not present in the second array.
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;
class Solution
{
    map<int, int> table;

public:
    Solution(vector<int> arr1, vector<int> arr2)
    {
        for (int i = 0; i < arr1.size(); i++)
        {
            table[arr1[i]];
        }
        for (int i = 0; i < arr2.size(); i++)
        {
            if (table.find(arr2[i]) != table.end())
                table.erase(arr2[i]);
        }
    }
    vector<int> getUnique()
    {
        vector<int> ans;
        for (auto x : table)
        {
            ans.push_back(x.first);
        }
        return ans;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 8,9, 0};
    vector<int> arr2 = {4, 5, 6, 7};
    Solution soln(arr1, arr2);
    vector<int> ans = soln.getUnique();
    for (auto x : ans)
        cout << x << "\t";
    return EXIT_SUCCESS;
}