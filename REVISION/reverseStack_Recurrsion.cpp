#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;
void InsertAtButton(stack<int> &stk, int value)
{
    if (stk.empty())
    {
        stk.push(value);
        return;
    }
    int x = stk.top();
    stk.pop();
    InsertAtButton(stk, value);
    stk.push(x);
}
void Reverse(stack<int> &stk)
{
    if (stk.empty())
    {
        return;
    }
    int x = stk.top();
    stk.pop();
    Reverse(stk);
    InsertAtButton(stk, x);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // Initialize a stack and push some elements
    stack<int> stk;
    cout << "Pushing 1 onto the stack.\n";
    stk.push(1);

    cout << "Pushing 2 onto the stack.\n";
    stk.push(2);

    cout << "Pushing 3 onto the stack.\n";
    stk.push(3);

    // Display the top element of the stack
    cout << "Current top element of the stack: " << stk.top() << endl;

    // Reverse the stack
    cout << "Reversing the stack...\n";
    Reverse(stk);

    // Display the new top element after reversing the stack
    cout << "New top element after reversing the stack: " << stk.top() << endl;

    return EXIT_SUCCESS;
}