#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

using namespace std;

int search(const vector<int>& arr, int key)
{
    int first = 0;
    int last = arr.size() - 1;
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
    cout << "How many elements do you have?" << endl;
    int size;
    cin >> size;

    if (size <= 0)
    {
        cout << "Invalid array size." << endl;
        return EXIT_FAILURE;
    }

    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i + 1 << ":" << endl;
        cin >> arr[i];
    }

    // Bubble Sort
    for (int i = 0; i < size - 1; i++)
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
        if (!flag)
        {
            break; // No swaps means the array is sorted
        }
    }

    cout << "Enter the element that you want to search for:" << endl;
    int key;
    cin >> key;

    int status = search(arr, key);
    if (status != -1)
    {
        cout << key << " found at index " << status << endl;
    }
    else
    {
        cout << key << " not found" << endl;
    }

    return EXIT_SUCCESS;
}
