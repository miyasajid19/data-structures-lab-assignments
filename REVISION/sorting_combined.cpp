#include <iostream>
#include <cstdlib>
using namespace std;
class Solution
{
public:
    void BubbleSort(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            bool flag = false;
            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    flag = true;
                }
            }
            if (not flag)
                break;
        }
    }
    void InsertionSort(int arr[], int size)
    {
        for (int i = 1; i < size; i++)
        {
            int current = arr[i];
            int j = i - 1;
            while (arr[j] > arr[j + 1] and j >= 0)
            {
                swap(arr[j], arr[j + 1]);
                j--;
            }
            arr[j + 1] = current;
        }
    }
    void selectionsort(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            int minimumIndex = i;
            for (int j = i; j < size; j++)
            {
                if (arr[minimumIndex] > arr[j])
                    minimumIndex = j;
            }
            if (minimumIndex != i)
                swap(arr[i], arr[minimumIndex]);
        }
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << "enter how many data do you have?? " << endl;
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << i + 1 << " ::" << endl;
        cin >> arr[i];
    }
    cout << "Unsorted array :: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    Solution soln;
    // soln.BubbleSort(arr, size);
    // soln.InsertionSort(arr, size);
    soln.selectionsort(arr, size);
    cout << "Sorted array :: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    return EXIT_SUCCESS;
}