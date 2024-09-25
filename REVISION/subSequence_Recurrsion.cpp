#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    void Subsequences(string str, int index, string current, vector<string> &result)
    {
        if (str.length() == index)
        {
            result.push_back(current);
            return;
        }
        Subsequences(str, index + 1, current + str[index], result);
        Subsequences(str, index + 1, current, result);
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution soln;
    vector<string> result;
    cout << "enter any string :: " << endl;
    string str;
    cin >> str;
    soln.Subsequences(str, 0, "", result);
    cout << "possible sebsequences :: " << endl;
    for (string x : result)
        cout << x << endl;
    return EXIT_SUCCESS;
}