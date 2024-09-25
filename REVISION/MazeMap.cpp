#include <iostream>
#include <cstdlib>
using namespace std;
class Solution
{
public:
    int MazeMapping(int row, int column, int rows, int columns)
    {
        if (row == rows - 1 and column == columns - 1)
            return 1;
        if (row > rows or columns > columns)
            return 0;
        return MazeMapping(row + 1, column, rows, columns) + MazeMapping(row, column + 1, rows, columns);
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution soln;
    cout << soln.MazeMapping(0, 0, 10, 4);
    return EXIT_SUCCESS;
}