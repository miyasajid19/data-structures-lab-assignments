#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;
stack<int> copyStack(stack<int> stk)
{
    stack<int> result;
    while (not stk.empty())
    {
        result.push(stk.top());
        stk.pop();
    }

    while (not result.empty())
    {
        stk.push(result.top());
        result.pop();
    }
    return stk;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    stack<int> stk;
    stk.push(1);
    cout << stk.top() << endl;
    stk.push(2);
    cout << stk.top() << endl;
    stk.push(3);
    cout << stk.top() << endl;
    stk.push(4);
    cout << stk.top() << endl;
    stk.push(5);
    cout << stk.top() << endl;
    cout << "---------------------------------------" << endl;
    stack<int> result = copyStack(stk);
    cout << result.top() << endl;
    result.pop();
    cout << result.top() << endl;
    result.pop();
    cout << result.top() << endl;
    result.pop();
    cout << result.top() << endl;
    result.pop();
    cout << result.top() << endl;
    result.pop();
    return EXIT_SUCCESS;
}