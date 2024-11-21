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

    void find(int key)
    {
        if (Find(root, key) == -1)
            cout << key << " :: Not found in tree" << endl;
        else
            cout << key << " :: Found in tree" << endl;
    }
    void find_NonRecurrsive( int key)
    {
        queue<Node *> Queue;
        Queue.push(root);
        while (not Queue.empty())
        {
            Node *headNode = Queue.front();
            Queue.pop();
            if (headNode == nullptr)
            {
                cout << key << " :: Not Found in tree " << endl;
                break;
            }
            if (headNode->value == key)
            {
                cout << key << " :: Found in tree " << endl;
                break;
            }
            if (key > headNode->value)
                Queue.push(headNode->right);
            else
                Queue.push(headNode->left);
        }
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

    cout << "How many data do you have? ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        bst.buildTree(value);
    }

    bst.InorderTraversal();
    bst.find(432);
    bst.find(13);

    bst.find_NonRecurrsive(432);
    bst.find_NonRecurrsive(13);
    return EXIT_SUCCESS;
}
