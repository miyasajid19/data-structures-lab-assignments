#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int start, int end)
{
    int PivotElement = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++)
        if (arr[i] <= PivotElement)
            count++;

    int PivotIndex = start + count;
    swap(arr[start], arr[PivotIndex]);
    int i = start, j = end;
    while (i < PivotIndex && j > PivotIndex)
    {
        while (arr[i] < PivotElement)
            i++;

        while (arr[j] > PivotElement)
            j--;

        if (i < PivotIndex && j > PivotIndex)
            swap(arr[i++], arr[j--]);
    }
    return PivotIndex;
}

void QuickSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;
    int PivotIndex = partition(arr, start, end);
    QuickSort(arr, start, PivotIndex - 1);
    QuickSort(arr, PivotIndex + 1, end);
}

int main()
{
    vector<int> arr = {3, 12, 31, 231, 231, 23, 12, 23, 124, 101, 0, 1, -1, -1, -110};
    cout << "Unsorted ::  " << endl;
    for (auto x : arr)
        cout << x << " ";
    cout << endl
         << endl;

    QuickSort(arr, 0, arr.size() - 1);

    cout << "Sorted" << endl;
    for (auto x : arr)
        cout << x << " ";
    cout << endl
         << endl;

    return EXIT_SUCCESS;
}
