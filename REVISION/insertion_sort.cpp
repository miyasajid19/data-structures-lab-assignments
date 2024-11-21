#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
void sort(vector<int> &arr)
{
    if (arr.size() < 2)
        return;
    for (int i = 1; i < arr.size(); i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (arr[j] > current and j>=0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}
int main()
{
    vector<int>arr={3,2,1,4,5};
    sort(arr);
    for (auto x: arr)
        cout<<x<<"\t";
    return EXIT_SUCCESS;
}