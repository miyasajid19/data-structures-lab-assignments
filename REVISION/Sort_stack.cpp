#include <iostream>
#include <stack>
using namespace std;

void insertInSortedOrder(stack<int> &stk, int element)
{

    if (stk.empty() || stk.top() <= element)
    {
        stk.push(element);
        return;
    }

    int topElement = stk.top();
    stk.pop();

    insertInSortedOrder(stk, element);

    stk.push(topElement);
}

void sortStack(stack<int> &stk)
{
    if (stk.empty())
    {
        return;
    }

    int topElement = stk.top();
    stk.pop();

    sortStack(stk);

    insertInSortedOrder(stk, topElement);
}

int main()
{
    stack<int> stk;

    stk.push(407);
    stk.push(432);
    stk.push(13);
    stk.push(39);
    stk.push(8);

    sortStack(stk);

    cout << "Stack elements after sorting (top to bottom): ";
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }

    return 0;
}
