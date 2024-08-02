#include<iostream>
using namespace std;
int main()
{
	cout<<"enter the dimensions of the matrix ";
	int row , column;
	cin>>row>>column;
	int arr[row][column];
		for (int i =0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			cout<<"Arr["<<i<<"]["<<j<<"]";
			cin>>arr[i][j];
		}
	}
	for (int i =0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
cout<<"sum of rows: ";
	for (int i=0;i<row;i++)
	{
		int sum=0;
		for (int j=0;j<column;j++)
		{
			sum+=arr[i][j];
			cout <<arr[i][j]<<" ";
		}
		cout<<"   sum of row "<<i+1<<" is "<<sum<<endl;
	}
cout<<"sum of columns"<<endl;
	for (int i=0;i<column;i++)
	{
		int sum=0;
		for (int j=0;j<row;j++)
		{
			sum+=arr[j][i];
			cout <<arr[j][i]<<" ";
		}
		cout<<"   sum of column "<<i+1<<" is "<<sum<<endl;
	}
	
}