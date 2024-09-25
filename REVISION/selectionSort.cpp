
#include <iostream>
#include <cstdlib>
using namespace std;
class Solution
{
public:
    void SelectionSorting(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            int minimumIndex = i;
            for (int j = i; j < size; j++)
            {
                if (arr[minimumIndex] > arr[j])
                {
                    minimumIndex = j;
                }
            }
            if (minimumIndex != i)
                swap(arr[minimumIndex], arr[i]);
        }
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution soln;
    cout << "how many data do you have ?? " << endl;
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << i + 1 << " : " << endl;
        cin >> arr[i];
    }
    cout << "unsorted array :: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i]<<" ";
    }
    cout << endl;
    soln.SelectionSorting(arr, size);
    cout << "sorted array :: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i]<< " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}