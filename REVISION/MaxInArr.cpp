#include <iostream>
#include <cstdlib>
using namespace std;
class Solution
{
public:
    int MaxInArr(int arr[], int index, int size)
    {
        if (index == size - 1)
            return arr[index];
        return max(arr[index], MaxInArr(arr, index + 1, size));
    }
    int MinInArr(int arr[], int index, int size)
    {
        if (index == size - 1)
            return arr[index];
        return min(arr[index], MaxInArr(arr, index + 1, size));
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int arr[] = {1, 4, 12, 8, 39, 432, 407, 2062, 2061};
    Solution soln;
    cout << soln.MaxInArr(arr, 0, sizeof(arr) / sizeof(arr[0])) << endl;
    cout << soln.MinInArr(arr, 0, sizeof(arr) / sizeof(arr[0])) << endl;
    return EXIT_SUCCESS;
}