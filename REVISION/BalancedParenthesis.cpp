#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>
using namespace std;
bool isBalanced(string str)
{
    stack<char> stk;
    for (char x : str)
    {
        if (x == '(' or x == '[' or x == '{')
        {
            stk.push(x);
        }
        else if (not stk.empty() and stk.top() == '(' and  x == ')')
        {
            stk.pop();
        }
        else if ( not stk.empty() and  stk.top() == '{' and x == '}')
        {
            stk.pop();
        }
        else if ( not stk.empty() and  stk.top() == '[' and  x == ']')
        {
            stk.pop();
        }
        else
        {
            return false;
        }
    }
    return stk.empty();
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << boolalpha;
    cout << "enter string of parenthesis :: ";
    string str;
    getline(cin, str);
    cout << isBalanced(str);
    return EXIT_SUCCESS;
}