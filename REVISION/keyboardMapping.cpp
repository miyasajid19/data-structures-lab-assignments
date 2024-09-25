#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

class Solution
{
public:
    void KeyboardCombination(string str, int index, string current, vector<string> map, vector<string> &result)
    {
        if (str.size() == index)
        {
            result.push_back(current);
            return;
        }
        int num = str[index] - '0';  // Convert character to integer
        if (num <= 1)
        {
            KeyboardCombination(str, index + 1, current, map, result); // Skip invalid digits like 0 and 1
            return;
        }
        for (int i = 0; i < map[num].size(); i++)  // Loop over the characters of the current digit
        {
            KeyboardCombination(str, index + 1, current + map[num][i], map, result);
        }
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string str = "4343726727384366597522394373422267334378436422685375336738376489";  // Input string of digits
    vector<string> result;
    Solution soln;
    soln.KeyboardCombination(str, 0, "", map, result);

    for (string x : result)
    {
        cout << x << "\n";  // Output all possible combinations
    }

    return EXIT_SUCCESS;
}
