#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

class Node
{
public:
    int value;
    Node *left, *right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

class BST
{
    Node *root;

    Node *BuildTree(Node *temp, int value)
    {
        if (temp == nullptr)
            return new Node(value);

        if (value < temp->value)
            temp->left = BuildTree(temp->left, value);
        else
            temp->right = BuildTree(temp->right, value);

        return temp;
    }

    void inorder(Node *temp)
    {
        if (temp == nullptr)
            return;

        inorder(temp->left);
        cout << temp->value << "\t";
        inorder(temp->right);
    }

    int Find(Node *temp, int key)
    {
        if (temp == nullptr)
            return -1;

        if (key > temp->value)
            return Find(temp->right, key);
        else if (key < temp->value)
            return Find(temp->left, key);
        else
            return temp->value;
    }
    int FindMax(Node *temp)
    {
        if (temp == nullptr)
            return INT_MIN;
        return max(temp->value, FindMax(temp->right));
    }

public:
    BST() : root(nullptr) {}

    void buildTree(int value)
    {
        root = BuildTree(root, value);
    }

    void InorderTraversal()
    {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }
    int MaxValue()
    {
        return FindMax(root);
    }
};

int main()
{
#ifndef JUDGE_ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !JUDGE_ONLINE
    BST bst;
    int n, value;

    cout << "How many data do you have? " << endl;
    cin >> n;

    cout << "Enter values: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        bst.buildTree(value);
    }
    cout << endl;

    bst.InorderTraversal();

    cout << "Maximum Element in BST :: " << bst.MaxValue();
    return EXIT_SUCCESS;
}
