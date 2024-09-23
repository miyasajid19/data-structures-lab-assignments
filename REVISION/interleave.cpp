#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;
void interleave(queue<int> &Q)
{
    int x = Q.size();
    queue<int> temp;
    for (int i = 0; i < x / 2; i++)
    {
        temp.push(Q.front());
        Q.pop();
    }
    // interleaving
    for (int i = 0; i < x; i++)
    {
        if (i % 2 == 0)
        {
            int a = temp.front();
            temp.pop();
            Q.push(a);
        }
        else
        {
            int a = Q.front();
            Q.pop();
            Q.push(a);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    queue<int> Q;
    for (int i = 0; i < 6; i++)
        Q.push(i);
    queue<int> temp = Q;
    cout << "original Queue ::: ";
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
    cout << "Interleaved Queue ::: ";
    interleave(Q);
    temp = Q;
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
    return EXIT_SUCCESS;
}