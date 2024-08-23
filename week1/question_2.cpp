#include<iostream>
using namespace std;
int main()
{
   #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
   #endif
	int size;
	cout<<"enter the size of array : "<<endl;
	cin>>size;
	int arr[size];
	for (int i =0;i<size;i++)
	{
		cout<<"Element "<<i+1<<endl;
		cin>>arr[i];
		
	}
	int uniquearr[size];
	for (int i=0;i<size;i++)
	{
		for (int j=1;j<size-i-1;j++)
		{
			if (arr[j]>arr[j+1])
			{
				int temp= arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	int k=0;
	int i;
	for ( i=0;i<size-1;i++)
	{
		if (arr[i]!=arr[i+1])
		{
			uniquearr[k++]=arr[i];
		}
	}
    cout<<"unique elements are : "<<endl;
	uniquearr[k++]=arr[i];
	for (i=0;i<k;i++)
	{
		cout<<uniquearr[i]<<" ";
	}
	return 0;
}