#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include "Stacks_linkedlist.h" 
using namespace std;
float compute(float first, float second, char const op)
{
    switch (op)
    {
    case '+':
        return first + second;
    case '-':
        return first - second;
    case '*':
        return first * second;
    case '/':
        return first / second;
    case '^':
        return pow(first, second);
    default:
        return 0;
    }
}
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
            float value = compute(stof(first), stof(second), a);
            stack.Push(to_string(value));
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
    cout << "Enter a valid postfix expression to evaluate: ";
    string str;
    cin >> str;

    string infix = evaluatePostfix(str);

    cout << "The result of the postfix expression is: " << infix << endl;

    return EXIT_SUCCESS;
}
