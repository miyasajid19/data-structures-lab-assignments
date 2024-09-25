#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class solution
{
public:
    string Remove(string str, char x)
    {
        string result;
        if (str.size() == 0)
            return "";
        if (str[0] == x)
            result += Remove(str.substr(1), x);
        else
            result += str[0] + Remove(str.substr(1), x);
        return result;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solution soln;
    string str;
    getline(cin, str);
    char x;
    cin >> x;
    cout << soln.Remove(str, x);
    return EXIT_SUCCESS;
}