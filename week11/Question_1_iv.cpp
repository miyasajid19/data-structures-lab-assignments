#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
void MergeArr(vector<int> &arr, int start, int middle, int end)
{
    int len1 = middle - start + 1;
    int len2 = end - middle;
    int *first = new int[len1];
    int *second = new int[len2];
    // assigning values for merging
    for (int i = 0; i < len1; i++)
        first[i] = arr[start + i];

    for (int i = 0; i < len2; i++)
        second[i] = arr[middle + 1 + i];
    // merging
    int index1 = 0, index2 = 0;
    int index = start;
    while (index1 < len1 and index2 < len2)
    {
        if (first[index1] < second[index2])
            arr[index++] = first[index1++];
        else
            arr[index++] = second[index2++];
    }
    while (index1 < len1)
        arr[index++] = first[index1++];

    while (index2 < len2)
        arr[index++] = second[index2++];

    delete[] first;
    delete[] second;
}
void Mergesort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;
    int middle = (start + end) / 2;
    Mergesort(arr, start, middle);     // sort the left part
    Mergesort(arr, middle + 1, end);   // solve right part
    MergeArr(arr, start, middle, end); // merge two sorted array
}
int main()
{
    vector<int> arr = {3, 12, 31, 231, 231, 23, 12, 23, 124, 101, 1 - 1, 1, -1, -1, -110};
    cout << "Unsorted ::  " << endl;
    for (auto x : arr)
        cout << x << " ";
    cout << endl
         << endl;

    Mergesort(arr, 0, arr.size() - 1);

    cout << "Sorted" << endl;
    for (auto x : arr)
        cout << x << " ";
    cout << endl
         << endl;
    return EXIT_SUCCESS;
}