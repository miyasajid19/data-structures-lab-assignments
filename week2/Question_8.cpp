#include <iostream>
#include <cstdlib>
using namespace std;

int countUnique(int *&arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    int count = 0;
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            ++count;
        }
    }
    return ++count;
}

int main() {

    int size;
    int *arr = nullptr;

    cout << "How many data do you have?" << endl;
    cin >> size;

    arr = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << endl << "Number of unique elements: " << countUnique(arr, size) << endl;

    delete[] arr;

    return EXIT_SUCCESS;
}
