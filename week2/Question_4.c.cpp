#include <iostream>
#include <cstdlib>
#include<string>
using namespace std;
string removeVowels(string a)
{
    string b;
    for (int i =0;i<a.length();i++)
    {
        if (a[i]!='a' and a[i]!='e' and a[i]!='i' and a[i]!='o' and a[i]!='u')
        {
            b.push_back(a[i]);
        }
    }
    return b;
}
int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
string a;
cout<<"enter string : "<<endl;
getline(cin,a);
cout<<removeVowels(a);
    return EXIT_SUCCESS;
}