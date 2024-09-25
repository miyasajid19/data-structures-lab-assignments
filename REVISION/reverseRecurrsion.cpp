#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
class solution
{
public:
    int reverse(int number, int result = 0)
    {
        if (number == 0)
            return result;
        result = result * 10 + number % 10;
        return reverse(number / 10, result);
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solution soln;
    cout << soln.reverse(432);
    return EXIT_SUCCESS;
}