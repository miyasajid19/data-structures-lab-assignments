#include <iostream>
#include <cstdlib>
#include <string>
#include "stacks.h" // Ensure this header file provides necessary stack implementation
using namespace std;

string evaluatePostfix(const string &str)
{
    Stacks<string> stack(str.length());
    string result;

    for (char a : str)
    {
        result = "";
        string x(1, a);

        if (x == "^" || x == "*" || x == "%" || x == "-" || x == "/" || x == "+")
        {
            string second = stack.Peek();
            stack.Pop();
            string first = stack.Peek();
            stack.Pop();
            result = '(' + first + ' ' + x + ' ' + second + ')';
            stack.Push(result);
            result = stack.Peek();
        }
        else
        {
            stack.Push(x);
        }
    }

    return stack.Peek();
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    cout << "Enter a postfix expression to convert it to infix: ";
    string str;
    cin >> str;

    string infix = evaluatePostfix(str);

    cout << "The corresponding infix expression is: " << infix << endl;

    return EXIT_SUCCESS;
}
