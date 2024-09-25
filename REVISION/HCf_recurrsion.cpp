#include <iostream>
#include <cstdlib>
using namespace std;
class Solution
{
public:
    int HCF_Division(int a, int b)
    {

        if (b == 0)
            return a;
        if (a > b)
            swap(a, b);
        return HCF_Division(a, b % a);
    }
    int HCF_Difference(int a, int b)
    {
        if (b == 0)
            return a;
        if (a > b)
            swap(a, b);
        return HCF_Difference(a, b - a);
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution soln;
    cout << soln.HCF_Difference(8, 32) << endl;
    cout << soln.HCF_Difference(20620408, 20610113) << endl;
    return EXIT_SUCCESS;
}