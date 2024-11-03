// Write a program to determine the most frequent element in an array. If there are
// multiple elements that are appearing the maximum number of times, then print any one
// of them.
#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;
class Solution
{
    map<int, int> table;

public:
    Solution(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            table[arr[i]]++;
        }
    }
    void displayTable()
    {
        cout<<endl<<endl;
        for (auto x: table)
            cout<<x.first<<"----->"<<x.second<<endl;
        cout<<endl<<endl;
    }
    int getMax()
    {
        map<int, int>::iterator itr = table.begin();
        for (map<int, int>::iterator x = table.begin(); x != table.end(); ++x)
        {
            if (itr->second > x->second)
            {
                cout<<"here"<<endl;
                itr = x;
            }
        }
        return itr->first;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int size;
    cout << "enter the size of array :: " << endl;
    cin >> size;
    vector<int> arr;
    for (int i = 0; i < size; i++)
    {
        int a;
        cout << "Enter element " << i + 1 << " :: " << endl;
        cin >> a;
        arr.push_back(a);
    }
    Solution soln(arr);
    soln.displayTable();
    cout << soln.getMax();
    return EXIT_SUCCESS;
}