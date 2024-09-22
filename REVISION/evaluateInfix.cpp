#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

float Result(float a, float b, const string &op)
{
    if (op == "^")
        return pow(a, b);
    else if (op == "*")
        return a * b;
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
        return a + b;
    else if (op == "-")
        return a - b;
    else
    {
        cout << "Error: Unknown operation!" << endl;
        return 0;
    }
}

float evaluatePrefix(const string &str)
{
    stack<float> stk;
    string token;

    // Iterate through the string in reverse
    for (int i = str.length() - 1; i >= 0; --i)
    {
        char current = str[i];

        // Skip spaces
        if (isspace(current))
            continue;

        // If the character is a digit (0-9)
        if (isdigit(current))
        {
            stk.push(current - '0'); // Convert char to float (e.g., '3' -> 3.0)
        }
        else // Otherwise, it's an operator
        {
            if (stk.size() < 2)
            {
                cout << "Error: Insufficient operands!" << endl;
                return 0;
            }
            float first = stk.top();
            stk.pop();
            float second = stk.top();
            stk.pop();
            float answer = Result(first, second, string(1, current));
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
    cout << "Enter the prefix expression (single digits only, use spaces): " << endl;
    string str;
    getline(cin, str);
    float result = evaluatePrefix(str);
    cout << "The result of the prefix operation is: " << result << endl;
    return EXIT_SUCCESS;
}
