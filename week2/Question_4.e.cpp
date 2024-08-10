#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
string toUppercase(string a)
{
    for (int i =0;i<a.size();i++)
    {
        a[i]=a[i]-32;
    }
    return a;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string a;
    cout << "enter string : " << endl;
    getline(cin, a);
cout<<toUppercase(a);
    return EXIT_SUCCESS;
}