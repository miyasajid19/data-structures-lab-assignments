#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;
int FindMinimumIndex(queue<int> q, int sortedIndex)
{
    int minimumIndex = -1;
    int minimumvalue = INT_MAX;
    for (int i = 0; i < q.size(); i++)
    {
        int current = q.front();
        if (current < minimumvalue and i <= sortedIndex)
        {
            minimumIndex = i;
            minimumvalue = current;
        }
        q.push(current);
    }
    return minimumIndex;
}
void insertAtRear(queue<int> &q, int minimumIndex)
{
    int minimumValue;
    int size = q.size();
    for (int i = 0; i <= minimumIndex; i++)
    {
        int current = q.front();
        q.pop();
        if (i != minimumIndex)
        {
            q.push(current);
        }
        else
        {
            minimumValue = current;
        }
    }
    q.push(minimumValue);
}
void sortQueue(queue<int> &q)
{
    for (int i = 0; i < q.size(); i++)
    {
        int minimumIndex = FindMinimumIndex(q, q.size() - i - 1);
        insertAtRear(q, minimumIndex);
    }
}
void display(queue<int> q)
{
    while (not q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    queue<int> q;
    q.push(3);
    q.push(1);
    q.push(4);
    q.push(-2);
    q.push(0);
    display(q);
    sortQueue(q);
    display(q);
    return EXIT_SUCCESS;
}