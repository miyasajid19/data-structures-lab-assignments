#include <iostream>
#include <cstdlib>
#include <string>
#include "stacks.h"

using namespace std;

template <typename T>
T reverse(T str) {
    Stacks<char> temp(str.size());
    for (int i = 0; i < str.size(); i++) {
        cout << str[i] << " ";
        temp.Push(str[i]);
    }
    cout << endl;

    T result;
    while (!temp.isEmpty()) {
        result += temp.Peek();
        temp.Pop();
    }

    return result;
}

int main() {
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    string str;
    cout << "Enter the string: ";
    getline(cin, str);

    string reversed = reverse(str);
    cout << "The reversed string is: " << reversed << endl;


    return EXIT_SUCCESS;
}
