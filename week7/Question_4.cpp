// Write a program that creates union and intersection lists from the two Linked Lists given
// as an input. The union list contains unique elements present in both the input Linked
// Lists and intersection list contains common elements present in the given lists. Order of
// elements in output lists doesn’t matter.
#include <iostream>
#include <cstdlib>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
    unordered_map<int, int> table;
    list<int> Intersection;
    list<int> Union;

public:
    Solution(list<int> list1, list<int> list2)
    {
        for (auto x : list1)
        {
            table[x]++;
            Union.push_back(x);
        }
        for (auto x : list2)
        {
            if (table.find(x) != table.end())
            {
                table[x]--;
                Intersection.push_back(x);
            }
            else
            {
                table[x]++;
                Union.push_back(x);
            }
        }
    }
    void display()
    {
        for (auto x : table)
        {
            cout << x.first << "----->" << x.second << endl;
        }
    }
    list<int> GetIntersection()
    {
        return Intersection;
    }
    list<int> GetUnion()
    {
        return Union;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    list<int> list1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    list<int> list2 = {4, 5, 6, 7, 10, 11, 12};
    Solution soln(list1, list2);
    // soln.display();
    list<int> Intersection = soln.GetIntersection();
    list<int> Union = soln.GetUnion();
    cout<<"Intersection :: ";
    for (auto x : Intersection)
        cout << x << "\t";
    cout << endl;
    cout<<"Union :: ";
    for (auto x : Union)
        cout << x << "\t";
    cout << endl;
    return EXIT_SUCCESS;
}