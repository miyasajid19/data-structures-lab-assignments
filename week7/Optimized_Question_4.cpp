#include <iostream>
#include <unordered_set>
#include <list>
using namespace std;

class Solution
{
    unordered_set<int> UnionSet;
    unordered_set<int> IntersectionSet;

public:
    Solution(const list<int> &list1, const list<int> &list2)
    {
        // Process list1 for union
        for (int num : list1)
        {
            UnionSet.insert(num);
        }

        // Process list2 for union and intersection
        for (int num : list2)
        {
            if (UnionSet.count(num))
            {
                IntersectionSet.insert(num); // If present in UnionSet, add to intersection
            }
            UnionSet.insert(num); // Always add to union
        }
    }

    list<int> getIntersection()
    {
        return list<int>(IntersectionSet.begin(), IntersectionSet.end());
    }

    list<int> getUnion()
    {
        return list<int>(UnionSet.begin(), UnionSet.end());
    }
};

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    list<int> list1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 4, 1};
    list<int> list2 = {4, 5, 6, 7, 10, 11, 12, 4};
    Solution soln(list1, list2);

    // Display Intersection
    list<int> intersection = soln.getIntersection(); // duplicate values will be removed because of using unordered_set
    cout << "Intersection: \n";
    for (int num : intersection)
    {
        cout << num << "\t";
    }
    cout << endl;

    // Display Union
    list<int> unionList = soln.getUnion(); // duplicate values will be removed because of using unordered_set
    cout << "Union: \n";
    for (int num : unionList)
    {
        cout << num << "\t";
    }
    cout << endl;

    return EXIT_SUCCESS;
}
