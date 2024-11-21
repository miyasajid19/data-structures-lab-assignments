#include <iostream>
#include <queue>
#include <stack>

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

    void levelorder(Node *node)
    {
        if (!node)
        {
            cout << "Tree is empty." << endl;
            return;
        }

        queue<Node *> Queue;
        Queue.push(node);

        int level = 0;
        while (!Queue.empty())
        {
            int levelSize = Queue.size();
            cout << "Level " << level++ << " :: ";
            while (levelSize--)
            {
                Node *current = Queue.front();
                Queue.pop();

                cout << current->value << '\t';

                if (current->left)
                    Queue.push(current->left);
                if (current->right)
                    Queue.push(current->right);
            }
            cout << endl;
        }
    }

    Node *buildTree(Node *node, int value)
    {
        if (!node)
            return new Node(value);

        if (value < node->value)
            node->left = buildTree(node->left, value);
        else if (value > node->value)
            node->right = buildTree(node->right, value);

        return node;
    }

    void inorder(Node *node)
    {
        stack<Node *> stk;
        Node *current = node;

        while (current || !stk.empty())
        {
            while (current)
            {
                stk.push(current);
                current = current->left;
            }
            current = stk.top();
            stk.pop();
            cout << current->value << "\t";
            current = current->right;
        }
    }

public:
    BST() : root(nullptr) {}

    void BuildTree()
    {
        cout << "Enter elements to build the BST (enter -1 to stop): " << endl;
        int value;
        while (cin >> value && value != -1)
            root = buildTree(root, value);
    }

    void levelOrderTraversal()
    {
        cout << "Level Order Traversal:" << endl;
        levelorder(root);
        cout << endl;
    }

    void inorderTraversal()
    {
        cout << "Inorder Traversal ::: ";
        inorder(root);
        cout << endl;
    }
};

int main()
{
    BST bst;
    bst.BuildTree();
    bst.levelOrderTraversal();
    bst.inorderTraversal();

    return 0;
}
