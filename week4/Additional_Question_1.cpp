#include <iostream>
#include <cstdlib>
#include <cmath>
#include "circularQueue.h"

using namespace std;

void Solution(long long num, Queue<long long> &queue)
{
    for (long long i = 1; i < num; i++)
    {
        long long x = i;
        long long ans = 0;
        long long j = 1;
        while (x != 0)
        {
            long long bit = x & 1; 
            ans += bit * j; 
            x >>= 1; 
            j *= 10; 
        }
        queue.Enqueue(ans);
    }
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
cout<<"how many data do you have?";
long long num;
cin>>num;
    Queue<long long> result(num);
    Solution(num, result);
    result.Display();

    return EXIT_SUCCESS;
}
