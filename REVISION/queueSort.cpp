#include <iostream>
#include <cstdlib>
#include <queue>
#include <climits> // For INT_MAX
using namespace std;

int FindMinimumIndex(queue<int> q, int sortedIndex)
{
    int minimumIndex = -1;
    int minimumValue = INT_MAX;
    int size = q.size(); // Store the initial size

    for (int i = 0; i < size; i++)
    {
        int current = q.front();
        q.pop();

        // We only consider the first (sortedIndex + 1) elements
        if (current < minimumValue && i <= sortedIndex)
        {
            minimumIndex = i;
            minimumValue = current;
        }

        q.push(current);
    }

    return minimumIndex;
}

void insertAtRear(queue<int> &q, int minimumIndex)
{
    int minimumValue;
    int size = q.size();

    for (int i = 0; i < size; i++)
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
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
        int minimumIndex = FindMinimumIndex(q, size - i - 1);
        insertAtRear(q, minimumIndex);
    }
}

void display(queue<int> q)
{
    while (!q.empty())
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
#endif // !ONLINE_JUDGE
    queue<int> q;
    q.push(407);
    q.push(432);
    q.push(8);
    q.push(13);
    q.push(4);
    q.push(1);
    q.push(2062);
    q.push(2061);

    cout << "Original queue: ";
    display(q);

    sortQueue(q);

    cout << "Sorted queue: ";
    display(q);

    return EXIT_SUCCESS;
}
