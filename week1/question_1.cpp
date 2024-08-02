#include <iostream>
#include <cstdlib>
#include <typeinfo>
using namespace std;

void menu()
{
    cout << "1. Create array" << endl;
    cout << "2. Display array" << endl;
    cout << "3. Insert into array" << endl;
    cout << "4. Delete from array" << endl;
    cout << "5. Linear search in array" << endl;
    cout << "6. Exit the program" << endl;
}

void createArray(int *&arr, int &size)
{
    cout << "Enter the size of the array: ";
    cin >> size;
    arr = new int[size];
    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void displayArray(int *arr, int size)
{
    if (size == 0)
    {
        cout << "Array is empty!" << endl;
        return;
    }
    cout << "Array elements are: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertIntoArray(int *&arr, int &size)
{
    int pos, value;
    cout << "Enter position to insert (0-based index): ";
    cin >> pos;
    cout << "Enter value to insert: ";
    cin >> value;

    int newSize = max(size, pos + 1);
    int *newArr = new int[newSize];

    // Copy elements up to the insertion position
    for (int i = 0; i < pos; i++)
    {
        newArr[i] = (i < size) ? arr[i] : 0; // Fill gaps with zeros
    }

    // Insert the new value
    newArr[pos] = value;

    // Copy remaining elements
    for (int i = pos + 1; i < newSize; i++)
    {
        newArr[i] = (i - 1 < size) ? arr[i - 1] : 0;
    }

    delete[] arr;
    arr = newArr;
    size = newSize;
}

void deleteFromArray(int *&arr, int &size)
{
    int pos;
    cout << "Enter position to delete (0-based index): ";
    cin >> pos;
    if (pos < 0 || pos >= size)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    int *newArr = new int[size - 1];
    for (int i = 0; i < pos; i++)
    {
        newArr[i] = arr[i];
    }
    for (int i = pos + 1; i < size; i++)
    {
        newArr[i - 1] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size--;
}

void linearSearch(int *arr, int size)
{
    int value;
    cout << "Enter value to search: ";
    cin >> value;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            cout << "Value found at position " << i << endl;
            return;
        }
    }
    cout << "Value not found in the array" << endl;
}

int main()
{
    int *arr = nullptr;
    int size = 0;
    int choice;

    while (true)
    {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createArray(arr, size);
            cout << "Array created" << endl;
            break;
        case 2:
            displayArray(arr, size);
            break;
        case 3:
            insertIntoArray(arr, size);
            break;
        case 4:
            deleteFromArray(arr, size);
            break;
        case 5:
            linearSearch(arr, size);
            break;
        case 6:
            delete[] arr;
            cout << "Exiting program..." << endl;
            return EXIT_SUCCESS;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }

            cin.ignore(); 
            cout << "Press Enter to continue...";
            cin.get(); 
    return EXIT_SUCCESS;
}
