#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class Stacks
{
    int size;
    int capacity;
    char *arr;

public:
    Stacks() {}
    Stacks(int capacity)
    {
        this->size = 0;
        this->capacity = capacity;
        arr = new char[capacity + 1];
    }
    void setStack(int capacity)
    {
        this->size = 0;
        this->capacity = capacity;
        arr = new char[capacity + 1];
    }
    void reStack(int capacity)
    {
        this->capacity = capacity;
        char *arr1 = new char[capacity + 1];
        for (int i = 0; i < size; i++)
        {
            arr1[i] = arr[i];
        }
        delete[] arr;
        arr = arr1;
    }
    bool isEmpty()
    {
        return this->size == 0;
    }
    bool isFull()
    {
        return this->size == this->capacity;
    }
    int Size()
    {
        return size;
    }
    void Push(char value)
    {
        if (isFull())
        {
            cout << "stack overflow" << endl;
            return;
        }
        arr[this->size++] = value;
    }
    void Pop()
    {
        if (isEmpty())
        {
            cout << "stack underflow" << endl;
            return;
        }
        this->size--;
    }
    char Peek()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        return arr[this->size - 1];
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return;
        }
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
string reverse(string str)
{
    Stacks temp(str.size());
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
        temp.Push(str[i]);
    }
    cout << endl;
    string result;
    while (not temp.isEmpty())
    {
        result += temp.Peek();
        temp.Pop();
    }
    return result;
}
int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    Stacks stack;
    int capacity, choice, value;
    string str;
    cout << "Enter the string";
    getline(cin, str);
    string reversed = reverse(str);
    cout << "the reversed string is " << reversed;
    return EXIT_SUCCESS;
}
