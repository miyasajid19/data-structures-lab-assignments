#include <iostream>
#include<vector>
using namespace std;
class DiagonalMatrix
{
    public:
    vector <int> arr;
    // DiagonalMatrix() = default;

    // // Constructor with initialization
    // explicit DiagonalMatrix(const vector<int>& values) : arr(values) {}
    DiagonalMatrix()
    {

    }
    DiagonalMatrix(int a)
    {
arr.push_back(a);
    }
    DiagonalMatrix(int a,int b)
    {
arr.push_back(a);
arr.push_back(b);
    }
    DiagonalMatrix(int a,int b, int c)
    {
arr.push_back(a);
arr.push_back(b);
arr.push_back(c);
    }

    void display()
    {
        for (int i=0;i<arr.size();i++)
        {
            for( int j=0;j<arr.size();j++)
            {
                if (i==j)
                {
                    cout<<arr[j]<<" ";
                }
                else{
                    cout<<0<<" ";
                }
            }
            cout<<endl;
        }
    }
~DiagonalMatrix() = default;    
};
main()
{
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
// two dimensional diagonal array
DiagonalMatrix d1;
d1.arr.push_back(1);
d1.arr.push_back(2);
d1.display();
cout<<endl<<endl;
//3 dimensional diagonal array
DiagonalMatrix d2(1,2,3);
d2.display();
    return 0;
}

