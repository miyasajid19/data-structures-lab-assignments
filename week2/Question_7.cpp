// Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an inversion
// if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to count the number
// of inversions in an array.
#include <iostream>
#include <cstdlib>
using namespace std;
int countInversion(int *arr, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (i < j and arr[i] > arr[j])
            {
                ++count;
            }
        }
    }
    return count;
}
int main()
{
    int *arr = nullptr;
    int size;
    cout << "enter the size of array : ";
    cin >> size;
    arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << i + 1<<"\t";
        cin >> arr[i];
    }
    cout << endl
         << "Number of inversions: " << countInversion(arr, size) << endl;
    return EXIT_SUCCESS;
}