#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    #ifndef JUDGE_ONLINE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    
    int arr[size];
    for (int i = 0; i < size; i++) {
        cout << "Enter the element " << i + 1 << ": ";
        cin >> arr[i];
    }

    for (int i = 0; i < size; i++) {
        int flag = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }

    return EXIT_SUCCESS;
}
