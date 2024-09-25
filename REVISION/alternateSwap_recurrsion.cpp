#include <iostream>
#include <cstdlib>
using namespace std;
class Solution
{
public:
    void AlternateSwap(int arr[], int size, int index)
    {
        if (index >= size-1)
            return;
        swap(arr[index], arr[index + 1]);
        AlternateSwap(arr, size, index+2);
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution soln;
    int arr[] = {432, 407, 13, 8, 1, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    soln.AlternateSwap(arr, size, 0);
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return EXIT_SUCCESS;
}