#include <iostream>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;
void Reverse(queue<int> &Q)
{
    if (Q.empty())
    {
        return;
    }
    int x = Q.front();
    Q.pop();
    Reverse(Q);
    Q.push(x);
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    queue<int> Q;
    for (int i = 0; i < 5; i++)
    {
        int x;
        cin >> x;
        Q.push(x);
    }
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