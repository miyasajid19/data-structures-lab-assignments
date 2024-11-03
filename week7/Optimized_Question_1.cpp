#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int getMostFrequentElement(const vector<int>& arr) {
        unordered_map<int, int> frequency;
        int maxElement = arr[0];  // Initialize with the first element
        int maxCount = 0;

        for (int num : arr) {
            int count = ++frequency[num];  // Increment and fetch updated count
            if (count > maxCount) {
                maxCount = count;
                maxElement = num;
            }
        }

        return maxElement;
    }
};

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    Solution soln;
    cout << "Most frequent element: " << soln.getMostFrequentElement(arr) << endl;

    return 0;
}
