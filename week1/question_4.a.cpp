#include<iostream>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
	int size;
	cout<<"enter the size of array ";
	cin>>size;
	int arr[size];
	for (int i =0;i<size;i++)
	{
		cin>>arr[i];
	}
    cout<<"orignal array : "<<endl;
		for (int i =0;i<size;i++)
	{
	cout<<arr[i]<<" ";
	}
	int range=size/2;
	for (int i=0,  j=size-1;i<range;i++,j--)
	{
		int temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
    cout<<endl<<"reversed array : "<<endl;
		for (int i =0;i<size;i++)
	{
	cout<<arr[i]<<" ";
	}
	return 0;
}