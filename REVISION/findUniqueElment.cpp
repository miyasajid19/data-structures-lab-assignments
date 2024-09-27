/*
lets say you have n array and there are all repeated elements except one. find the the unique number in
linear time complexity
*/
#include <iostream>
#include <cstdlib>
using namespace std;
class solution
{
public:
    int Unique(int arr[], int size)
    {
        int unique = 0;
        for (int i = 0; i < size; i++)
        {
            unique ^= arr[i];
        }
        return unique;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << "enter how many data do you have??";
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << i + 1 << " :: " << endl;
        cin >> arr[i];
    }
    solution soln;
    cout << "The unique element present in the array is " << soln.Unique(arr, size) << endl;
    return EXIT_SUCCESS;
}