#include <iostream>
#include <cstdlib>
#include <stack>
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

string infixToPostfix(string str)
{
    stack<char> stk;
    string result;
    for (char x : str)
    {
        // If operand (a-z, A-Z, 0-9), add it to the result
        if ((x >= 'a' and x <= 'z') or (x >= 'A' and x <= 'Z') or (x >= '0' and x <= '9'))
        {
            result += x;
        }
        // If opening bracket, push it to stack
        else if (x == '(')
        {
            stk.push(x);
        }
        // If closing bracket, pop till matching '(' is found
        else if (x == ')')
        {
            while (!stk.empty() and stk.top() != '(')
            {
                result += stk.top();
                stk.pop();
            }
            if (!stk.empty() and stk.top() == '(')
            {
                stk.pop();
            }
        }
        // Operator case
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
    // Pop all remaining operators from the stack
    while (!stk.empty())
    {
        result += stk.top();
        stk.pop();
    }
    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << infixToPostfix("A+C*B/D^E-F%G");
    return EXIT_SUCCESS;
}
