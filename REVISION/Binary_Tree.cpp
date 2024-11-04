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
    Node(int value)
    {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};
class Tree
{
    Node *root;
    Node *buildTree(Node *temp)
    {
        int value;
        cout << "Enter value(-1 for termination)" << endl;
        cin >> value;

        // base case
        if (value == -1)
            return nullptr;

        temp = new Node(value);

        cout << "Left Node for " << temp->value << endl;
        temp->left = buildTree(temp->left);

        cout << "Right Node for " << temp->value << endl;
        temp->right = buildTree(temp->right);

        return temp;
    }

public:
    Tree()
    {
        root = nullptr;
    }
    void BuildTree()
    {
        root = buildTree(root);
        cout << "Tree has been intialized\n";
    }
    void LevelWiseTraversal()
    {
        queue<Node *> Queue;
        Queue.push(root);
        Queue.push(nullptr);
        int level = 0;
        while (not Queue.empty())
        {
            Node *frontNode = Queue.front();
            Queue.pop();
            if (frontNode == nullptr)
            {
                cout << "Level " << level++;
                cout << endl;
                if (not Queue.empty())
                {
                    Queue.push(nullptr);
                }
            }
            else
            {
                cout << frontNode->value << "\t";
                if (frontNode->left)
                {
                    Queue.push(frontNode->left);
                }
                if (frontNode->right)
                {
                    Queue.push(frontNode->right);
                }
            }
        }
    }
};
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif
    Tree tree;
    tree.BuildTree();
    tree.LevelWiseTraversal();
    return EXIT_SUCCESS;
}