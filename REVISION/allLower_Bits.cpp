#include <iostream>
#include <queue>
using namespace std;

// Function to generate binary representation of numbers from 1 to num-1
queue<long long> allBits(long long int num)
{
    queue<long long> result;

    for (long long i = 1; i < num; i++)
    {
        long long x = i;
        long long ans = 0;
        long long j = 1;
        while (x != 0)
        {
            int bit = x & 1;
            ans += bit * j;
            x >>= 1;
            j *= 10;
        }
        result.push(ans); 
    }
    
    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // Generate binary representations of numbers from 1 to 9
    queue<long long> result = allBits(10);

    // Print all binary numbers stored in the queue
    while (!result.empty())
    {
        cout << result.front() <<endl; // Print the front element
        result.pop();                  // Remove the front element
    }

    return EXIT_SUCCESS;
}
