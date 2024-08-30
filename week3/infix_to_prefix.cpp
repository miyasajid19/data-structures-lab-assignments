#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include "stacks.h"
using namespace std;

int precedence(string x)
{
    if (x == "^")
    {
        return 3;
    }
    else if (x == "*" or x == "/" or x == "%")
    {
        return 2;
    }
    else if (x == "+" or x == "-")
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string InfixToPrefix(string str)
{
    Stacks<string> stack(str.size());
    string result;

    // Reverse the input expression
    reverse(str.begin(), str.end());

    for (char a : str)
    {
        string x(1, a);

        // Corrected condition to check if x is an operand (lowercase, uppercase letters, or digits)
        if ((x >= "a" and x <= "z") or (x >= "A" and x <= "Z") or (x >= "0" and x <= "9"))
        {
            result += x; // Append operand to result
        }
        else if (x == ")")
        {
            stack.Push(x); // Treat closing parenthesis as opening one (because of reverse)
        }
        else if (x == "(")
        {
            // Pop until we find a closing parenthesis (which was originally opening)
            while (!stack.isEmpty() and stack.Peek() != ")")
            {
                result += stack.Peek();
                stack.Pop();
            }
            if (!stack.isEmpty())
            {
                stack.Pop(); // Pop the closing parenthesis ')'
            }
        }
        else
        {
            // Handle operators by comparing precedence
            while (!stack.isEmpty() and precedence(x) <= precedence(stack.Peek()))
            {
                result += stack.Peek();
                stack.Pop();
            }
            stack.Push(x); // Push the current operator onto the stack
        }
    }

    // Pop the remaining operators from the stack
    while (!stack.isEmpty())
    {
        result += stack.Peek();
        stack.Pop();
    }

    // Reverse the result to get the prefix notation
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    cout << InfixToPrefix("(a-b/c)*(a/k-l)") << endl;
    return EXIT_SUCCESS;
}
