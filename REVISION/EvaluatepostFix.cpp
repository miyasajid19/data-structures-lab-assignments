#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

float Result(float a, float b, const string &op)
{
    if (op == "^")
    {
        return pow(a, b);
    }
    else if (op == "*")
    {
        return a * b;
    }
    else if (op == "/")
    {
        if (b != 0)
            return a / b;
        else
        {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
    }
    else if (op == "%")
    {
        if (b != 0)
            return fmod(a, b);
        else
        {
            cout << "Error: Modulus by zero!" << endl;
            return 0;
        }
    }
    else if (op == "+")
    {
        return a + b;
    }
    else if (op == "-")
    {
        return a - b;
    }
    else
    {
        cout << "Error: Unknown operation!" << endl;
        return 0;
    }
}

float evaluatePostfix(const string &str)
{
    stack<float> stk;

    for (auto x : str)
    {
        // If the character is a digit (0-9)
        if (isdigit(x))
        {
            stk.push(x - '0'); // Convert char to float (e.g., '3' -> 3.0)
        }
        else if (isspace(x))
        {
            continue; // Skip spaces
        }
        else // Otherwise, it's an operator
        {
            float second = stk.top();
            stk.pop();
            float first = stk.top();
            stk.pop();
            float answer = Result(first, second, string(1, x));
            stk.push(answer);
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
    cout << "Enter the postfix expression (single digits only): " << endl;
    string str;
    getline(cin, str);
    float result = evaluatePostfix(str);
    cout << "The result of the postfix operation is: " << result << endl;
    return EXIT_SUCCESS;
}
