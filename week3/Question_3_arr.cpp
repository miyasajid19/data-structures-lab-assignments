#include <iostream>
#include <cstdlib>
#include <string>
#include "stacks.h"
using namespace std;
bool isBalanced(string str)
{
    Stacks<char> stack(str.size());
    for (int i = 0; i < str.size(); i++)
    {
        char a = str[i];
        if (a == '[' || a == '{' || a == '(')
        {
            stack.Push(a);
        }
        else if (a == ')' and not stack.isEmpty() and stack.Peek() == '(')
        {
            stack.Pop();
        }
        else if (a == '}' and not stack.isEmpty() and stack.Peek() == '{')
        {
            stack.Pop();
        }
        else if (a == ']' and not stack.isEmpty() and stack.Peek() == '[')
        {
            stack.Pop();
        }
        else
        {
            return false;
        }
    }
    return stack.isEmpty();
}
int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    string str;
    cout << "enter string to check :: ";
    cin >> str;
    if (isBalanced(str))
    {
        cout << "balanced";
    }
    else
    {
        cout << "not balanced";
    }
    return EXIT_SUCCESS;
}