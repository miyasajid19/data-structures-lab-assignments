#include <iostream>
#include <cstdlib>
using namespace std;
class Solution
{
public:
    int Power(int num, int index)
    {
        if (index == 0)
            return 1;
        if (index % 2 == 0)
        {
            int result = Power(num, index / 2);
            return result * result;
        }
        else
        {
            int result = Power(num, (index - 1) / 2);
            return num * result * result;
        }
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
Solution soln;
cout<<soln.Power(232,3);
    return EXIT_SUCCESS;
}