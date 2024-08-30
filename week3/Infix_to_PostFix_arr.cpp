#include <iostream>
#include <cstdlib>
#include <string>
#include "stacks.h"
using namespace std;
int Precedence(char x)
{
    if (x == '^')
    {
        return 3;
    }
    else if (x == '*' or x == '%' or x == '/')
    {
        return 2;
    }
    else if (x == '+' or x == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
string InfixToPostFix(string str)
{
    char x;
    string result;
    Stacks<char> stack(str.size());
    for (int i = 0; i < str.size(); i++)
    {
        x = str[i];
        if ((x >= '0' and x<='9')or(x >= 'a' and x <= 'z') or (x >= 'A' and x <= 'Z'))
        {
            result += x;
        }
        else if (x == '(')
        {
            stack.Push(x);
        }
        else if (x == ')')
        {
            while (not stack.isEmpty() and stack.Peek() != '(')
            {
                result += stack.Peek();
                stack.Pop();
            }
            if (not stack.isEmpty()and stack.Peek()=='(')
            {
                stack.Pop();
            }
        }
        else
        {
            while (not stack.isEmpty() and Precedence(stack.Peek()) >= Precedence(x))
            {
                result += stack.Peek();
                stack.Pop();
            }
            stack.Push(x);
        } 
    }while (not stack.isEmpty())
    {
        result+=stack.Peek();
        stack.Pop();
    }
    return result;
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    string str;
    cout << "Enter infix expression: ";
    cin >> str;
    string postfix = InfixToPostFix(str);
    cout << "Postfix expression: " << postfix << endl;

    return EXIT_SUCCESS;
}