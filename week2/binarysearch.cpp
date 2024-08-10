#include <iostream>
#include <cstdlib>
using namespace std;
int search(int arr[], int size, int key)
{
    int first = 0;
    int last = size - 1;
    while (first <= last)
    {
        int middle = (first + last) / 2;
        if (arr[middle] == key)
        {
            return middle;
        }
        else if (arr[middle] < key)

        {
            first = middle + 1;
        }
        else
        {
            last = middle - 1;
        }
    }
    return -1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << "how many elements do you have?" << endl;
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "enter the element " << i + 1 << endl;
        cin >> arr[i];
    }
    // bubble sorting
    for (int i = 0; i < size; i++)
    {
        bool flag = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // int temp = arr[j];
                // arr[j] = arr[j + 1];
                // arr[j + 1] = temp;
                swap(arr[j],arr[j+1]);
                flag = true;
            }
        }
        if (flag)
        {
            break;
        }
    }
    cout << "enter the element that you want to search?" << endl;
    int key;
    cin >> key;
    int status = search(arr, size, key);
    if (status != -1)
    {
        cout << key << " found in index " << status << endl;
    }
    else
    {
        cout << key << " not found" << endl;
    }
    return EXIT_SUCCESS;
}