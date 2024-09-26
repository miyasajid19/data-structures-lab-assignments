#include <iostream>
#include <cstdlib>
#include <stack>
#include <algorithm>
using namespace std;

int precedence(char x)
{
    if (x == '^')
    {
        return 3;
    }
    else if (x == '*' or x == '/' or x == '%')
    {
        return 2;
    }
    else if (x == '+' or x == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

string infixToPrefix(string str)
{
    reverse(str.begin(), str.end());
    stack<char> stk;
    string result;
    for (char x : str)
    {
        if ((x >= 'a' and x <= 'z') or (x >= 'A' and x <= 'Z') or (x >= '0' and x <= '9'))
        {
            result += x;
        }
        else if (x == ')')
        {
            stk.push(x);
        }
        else if (x == '(')
        {
            while (!stk.empty() and stk.top() != ')')
            {
                result += stk.top();
                stk.pop();
            }
            if (!stk.empty() and stk.top() == ')')
            {
                stk.pop();
            }
        }
        else
        {
            while (!stk.empty() and precedence(x) <= precedence(stk.top()))
            {
                result += stk.top();
                stk.pop();
            }
            stk.push(x);
        }
    }
    while (!stk.empty())
    {
        result += stk.top();
        stk.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    cout << "Enter the infix exppression : " << endl;
    string str;
    getline(cin, str);
    cout << "the equivalennt prefix operation is  :: " << infixToPrefix(str);
    return EXIT_SUCCESS;
}
