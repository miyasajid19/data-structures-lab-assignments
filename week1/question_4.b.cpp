#include<iostream>
using namespace std;
int main(){
	cout<<"enter the dimension of Matrix A : ";;
	int row1,column1;
	cin>>row1>>column1;
	int A[row1][column1];
	for (int i =0;i<row1;i++)
	{
		for(int j=0;j<column1;j++)
		{
			cout<<"A["<<i<<"]["<<j<<"]";
			cin>>A[i][j];
		}
	}
	cout<<"enter the dimension of Matrix B : ";;
	int row2,column2;
	cin>>row2>>column2;
	int B[row2][column2];
	for (int i =0;i<row2;i++)
	{
		for(int j=0;j<column2;j++)
		{
			cout<<"B["<<i<<"]["<<j<<"]";
			cin>>B[i][j];
		}
	}
	if (row2==column1)
	{
		int result[row1][column2];
		for (int i=0;i<row1;i++)
		{
			for(int j=0;j<column2;j++)
			{
				result[i][j]=0;
				for (int k=0;k<row2;k++)
				{
					result[i][j] += A[i][k] * B[k][j];
				}
			}
		}
			for (int i=0;i<row1;i++)
		{
			for(int j=0;j<column2;j++)
			
			{
				cout<<result[i][j]<<" ";	
			}
			cout<<endl;
		}
	}
	else
	{
		cout<<"matrix multiplication is not possible";
	}
		
}
