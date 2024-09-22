#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>
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
string postfixToInfix(string str)
{
    stack<string> stk;
    string result;
    for (char x : str)
    {
        if ((x >= 'a' and x <= 'z') or (x >= 'A' and x <= 'Z') or (x >= '0' and x <= '9'))
        {
            stk.push(string(1, x));
        }
        else
        {
            string second = stk.top();
            stk.pop();
            string first = stk.top();
            stk.pop();
            result = "(" + first + " " + x + " " + second + ")";
            stk.push(result);
        }
    }
    return stk.top();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << "Enter the infix exppression : " << endl;
    string str;
    getline(cin, str);
    cout << "the equivalennt postfix operation is  :: " << postfixToInfix(str);
    return EXIT_SUCCESS;
}
