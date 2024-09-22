#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>
#include <sstream>
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
    istringstream iss(str);
    string token;

    while (iss >> token)
    {
        // Check if the token is a number
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-'))
        {
            stk.push(stof(token)); // Convert string to float
        }
        else
        {
            if (stk.size() < 2)
            {
                cout << "Error: Insufficient values in the expression!" << endl;
                return 0;
            }
            float second = stk.top();
            stk.pop();
            float first = stk.top();
            stk.pop();
            float result = Result(first, second, token);
            stk.push(result);
        }
    }

    if (stk.size() != 1)
    {
        cout << "Error: The expression is not valid!" << endl;
        return 0;
    }

    return stk.top();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << "Enter the postfix expression (space-separated): " << endl;
    string str;
    getline(cin, str);
    float result = evaluatePostfix(str);
    cout << "The result of the postfix operation is: " << result << endl;
    return EXIT_SUCCESS;
}
