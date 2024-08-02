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
	cout<<"original matrix :  "<<endl;
			for (int i =0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	int result[column][row];
		for (int i =0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			result[j][i]=arr[i][j];
		}
	}
	cout<<"Transposed matrix :"<<endl;
		for (int i =0;i<column;i++)
	{
		for(int j=0;j<row;j++)
		{
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}