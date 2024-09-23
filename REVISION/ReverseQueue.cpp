#include <iostream>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;
void Reverse(queue<int> &Q)
{
    stack<int> temp;
    while (!Q.empty())
    {
        temp.push(Q.front());
        Q.pop();
    }
    while (!temp.empty())
    {
        Q.push(temp.top());
        temp.pop();
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    queue<int> Q;
    for (int i = 0; i < 5; i++)
        Q.push(i);
    queue<int> temp = Q;
    cout << "original Queue ::: ";
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
    cout << "Reversed Queue ::: ";
    Reverse(Q);
    temp = Q;
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
    return EXIT_SUCCESS;
}