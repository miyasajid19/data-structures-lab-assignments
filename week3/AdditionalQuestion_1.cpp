#include <iostream>
#include <cstdlib>
#include <vector>
#include "stacks.h"
using namespace std;
void previousSmaller(int *arr, int size, int *result)
{
    result[0] = -1;
    Stacks<int> stack(size);
    stack.Push(arr[0]);
    for (int i = 1; i < size; i++)
    {
        if (stack.Peek() > arr[i])
        {
            stack.Pop();
            stack.Push(arr[i]);
            result[i] = -1;
        }
        else
        {
            result[i] = stack.Peek();
        }
    }
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int size;
    cout << "enter the size of array :: " << endl;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << i + 1 << " ::: " << endl;
        cin >> arr[i];
    }

    int result[size];
    previousSmaller(arr, size, result);
    for (int i = 0; i < size; i++)
    {
        cout << result[i] << " ";
    }
    return EXIT_SUCCESS;
}