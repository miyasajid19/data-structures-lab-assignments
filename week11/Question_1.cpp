#include<iostream>
#include<cstdlib>
using  namespace std;
int main()
{
    #ifndef JUDGE_ONLINE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int size;
    cout<<"enter the size of array  "<<endl;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cout<<"enter the element "<<i+1<<endl;
        cin>>arr[i];
    }
    for (int i =0;i<size-1;i++)
    {
        for (int j=i+1;j<size;j++)
        {
            if (arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(int i =0;i<size;i++)
    {
        cout<<arr[i]<<"\t";
    }
    return EXIT_SUCCESS;
}