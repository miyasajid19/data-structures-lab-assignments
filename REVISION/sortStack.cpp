#include <iostream>
#include <stack>
using namespace std;

void sortStackUsingAuxiliaryStack(stack<int> &stk)
{
    stack<int> aux;

    while (!stk.empty())
    {
        int temp = stk.top();
        stk.pop();
        while (!aux.empty() && aux.top() > temp)
        {
            stk.push(aux.top());
            aux.pop();
        }

        aux.push(temp);
    }

    while (!aux.empty())
    {
        stk.push(aux.top());
        aux.pop();
    }
}

int main()
{
    stack<int> stk;

    stk.push(30);
    stk.push(10);
    stk.push(50);
    stk.push(20);
    stk.push(60);

    sortStackUsingAuxiliaryStack(stk);
    cout << "Stack elements after sorting (top to bottom): ";
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }

    return 0;
}
