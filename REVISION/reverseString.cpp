#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
using namespace std;
string Reverse(string str)
{
    stack<char> stk;
    string ans;
    for (char x : str)
    {
        stk.push(x);
    }
    while (not stk.empty())
    {
        ans += stk.top();
        stk.pop();
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string str;
    getline(cin, str);
    cout << "The Reverse is  : " << Reverse(str);
    return EXIT_SUCCESS;
}