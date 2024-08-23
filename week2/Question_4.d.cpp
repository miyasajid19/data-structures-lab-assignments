#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
string stringsort(string a)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size() - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                // char temp=a[j];
                // a[j]=a[j+1];
                // a[j+1]=temp;
                swap(a[j],a[j+1]);
            }
        }
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
    cout<<stringsort(a)<<endl;
    return EXIT_SUCCESS;
}