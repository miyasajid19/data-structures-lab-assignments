#include <iostream>
#include <cstdlib>
#include <string>
#include "CircularQueue.h"
using namespace std;
string NonRepeating(string str)
{
    int count[26]={0};
    Queue<char> queue(str.size());
    string ans="";
    for (char x : str)
    {
        queue.Enqueue(x);
        count[x-'a']++;
        while (not queue.isEmpty())
        {
            if(count[queue.Peek()-'a']>1)
            {
                queue.Dequeue();
            }else{
                ans+=queue.Peek();
                break;
            }
        }
        if(queue.isEmpty())
        {
            ans+="-1";
        }
    }
    return ans;
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    string str;
    cout << "enter string ::";
    cin >> str;
    
    cout<<NonRepeating(str);
    return EXIT_SUCCESS;
}