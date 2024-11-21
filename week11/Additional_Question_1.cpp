#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

void countsort(int arr[], int size)
{
    int k = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        k = max(k, arr[i]);
    }
    cout << "Maximum value: " << k << endl;

    int* count = new int[k + 1]();
    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= k; i++)
    {
        count[i] += count[i - 1];
    }

    int* output = new int[size];
    for (int i = size - 1; i >= 0; i--)
    {
        output[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }

    delete[] count;
    delete[] output;
}

int main()
{
#ifndef JUDGE_ONLINE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cout << "How many data do you have? " << endl;
    int size;
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    countsort(arr, size);

    cout << "\nSorted array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout <<arr[i] << endl;
    }

    delete[] arr;
    return EXIT_SUCCESS;
}