#include <iostream>
#include <cstdlib>
using namespace std;
class Solution
{
public:
    int mazeMap(int row, int column, int rows, int columns)
{
    if (row == rows - 1 and column == columns - 1)
        return 1;
    if (row >= rows or column > columns)
        return 0;
    return mazeMap(row + 1, column, rows, columns) + mazeMap(row, column + 1, rows, columns);
}
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution soln;
    cout << soln.mazeMap(0, 0, 432, 407);
    return EXIT_SUCCESS;
}