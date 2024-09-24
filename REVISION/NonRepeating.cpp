#include <iostream>
#include <cstdlib>
#include <string>
#include<queue>
using namespace std;
string NonRepeating(string str)
{
    int count[26]={0};
    queue<char> Queue;
    string ans="";
    for (char x : str)
    {
        Queue.push(x);
        count[x-'a']++;
        while (not Queue.empty())
        {
            if(count[Queue.front()-'a']>1)
            {
                Queue.pop();
            }else{
                ans+=Queue.front();
                break;
            }
        }
        if(Queue.empty())
        {
            ans+="-1";
        }
    }
    return ans;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string str;
    cout << "enter string ::";
    cin >> str;
    cout<<NonRepeating(str);
    return EXIT_SUCCESS;
}