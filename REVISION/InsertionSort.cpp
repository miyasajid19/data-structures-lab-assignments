#include <iostream>
#include <cstdlib>
using namespace std;
class solution
{
public:
    void insertionSort(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            int current = arr[i];
            int j = i - 1;
            while (arr[j] > current and j >= 0)
            {
                swap(arr[j + 1], arr[j]);
                j--;
            }
            arr[j + 1] = current;
        }
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int size;
    cout << "how many data do you have??" << endl;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "element " << i + 1 << " ::" << endl;
        cin >> arr[i];
    }
    cout << "Unsorted array :: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    solution soln;
    soln.insertionSort(arr,size);
    cout<<"sorted array :: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    return EXIT_SUCCESS;
}