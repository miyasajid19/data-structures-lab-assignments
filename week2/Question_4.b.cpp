#include <iostream>
#include <cstdlib>
#include<string>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
    string str;
    cout<<"enter any string"<<endl;
    getline(cin,str);
    for (int i =0;i<str.length()/2;i++)
    {
        swap(str[i],str[str.length()-i-1]);
    }
    cout<<str;
    return EXIT_SUCCESS;
}