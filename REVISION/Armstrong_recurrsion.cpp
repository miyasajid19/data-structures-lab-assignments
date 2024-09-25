#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
int FindNoOfDigits(int number)
{
    int index = 0;
    while (number)
    {
        ++index;
        number /= 10;
    }
    return index;
}
int Armstrong(int number, int index)
{
    if (number == 0)
    {
        return 0;
    }
    return pow(number % 10, index) + Armstrong(number / 10, index);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int number = 407;
    if (number == Armstrong(number, FindNoOfDigits(number)))
        cout << number << " is armstrong" << endl;
    else
        cout << number << " is not armnstrong" << endl;
    return EXIT_SUCCESS;
}