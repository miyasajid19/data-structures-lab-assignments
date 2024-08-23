// Write a program to concatenate one string to another string. 
#include <iostream>
#include <cstdlib>
#include<string>
using namespace std;
string add(string a, string b)
{
    return a+b;
}
int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
string first,second;
cout<<"enter first string "<<endl;
cin>>first;
cout<<"enter the second string "<<endl;
cin>>second;
string third=add(first,second);
cout<<third<<endl;
//
first.append(second);
cout<<first<<endl;
first.push_back('s'); 
cout<<first<<endl;
    return EXIT_SUCCESS;
}