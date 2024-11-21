#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;
class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};
class BST
{
    Node *root;
    void levelorder(Node *temp)
    {
        queue<Node *> Queue;
        int level = 0;
        cout << "level " << level << " :: ";
        Queue.push(temp);
        Queue.push(nullptr);
        while (not Queue.empty())
        {
            Node *TopNode = Queue.front();
            Queue.pop();
            if (TopNode == nullptr)
            {
                cout << endl;
                cout << "level " << ++level << " :: ";
                if (not Queue.empty())
                {
                    Queue.push(nullptr);
                }
            }
            else
            {
                cout << temp->value << '\t';
                if (TopNode->left)
                    Queue.push(TopNode->left);
                if (TopNode->right)
                    Queue.push(TopNode->right);
            }
        }
    }
    Node *buildTree(Node *temp, int value)
    {
        if (temp == nullptr)
            return new Node(value);

        if (value > temp->value)
            temp->right = buildTree(temp->right, value);
        if (value < temp->value)
            temp->left = buildTree(temp->left, value);
        return temp;
    }

public:
    BST() : root(nullptr) {}
    void BuildTree()
    {
        int value;
        cout << "Enter Element " << endl;
        cin >> value;
        while (value != -1)
        {
            root = buildTree(root, value);
            cout << "Enter Element :: " << endl;
            cin >> value;
        }
    }
    void levelOrderTraversal()
    {
        cout << "Level Order Traversal :: " << endl;
        levelorder(root);
        cout << endl;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    BST bst;
    int n, value;
    bst.BuildTree();
    bst.levelOrderTraversal();
    return EXIT_SUCCESS;
}