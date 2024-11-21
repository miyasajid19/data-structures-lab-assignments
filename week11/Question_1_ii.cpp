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
        cout << "Enter the element " << i + 1 << ": "<<endl;
        cin >> arr[i];
    }

    for(int i =1;i<size;i++)
    {
        int current =arr[i];
        int j=i-1;
        while (arr[j]>current && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }

    return EXIT_SUCCESS;
}
