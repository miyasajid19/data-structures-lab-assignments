#include <iostream>
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
        if (temp == nullptr)
        {
            cout << "Tree is empty." << endl;
            return;
        }

        queue<Node *> Queue;
        int level = 0;
        cout << "Level " << level << " :: ";
        Queue.push(temp);
        Queue.push(nullptr); // Marker for level separation

        while (!Queue.empty())
        {
            Node *TopNode = Queue.front();
            Queue.pop();

            if (TopNode == nullptr)
            {
                cout << endl;
                level++;
                if (!Queue.empty())
                {
                    cout << "Level " << level << " :: ";
                    Queue.push(nullptr); // Add marker for next level
                }
            }
            else
            {
                cout << TopNode->value << '\t';
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
        else if (value < temp->value)
            temp->left = buildTree(temp->left, value);

        return temp;
    }
    Node *FindMax(Node *temp)
    {
        while (temp->right != nullptr)
        {
            temp = temp->right;
        }
        return temp;
    }
    Node *FindMin(Node *temp)
    {
        while (temp->left != nullptr)
        {
            temp = temp->left;
        }
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
    Node *deleteNode(Node *temp, int value, bool replacementfromLefttoright = false)
    {
        if (temp = nullptr)
        {
            return temp;
        }
        if (value > temp->value)
        {
            temp->right = deleteNode(temp->right, value, replacementfromLefttoright);
        }
        else if (value < temp->value)
        {
            temp->left = deleteNode(temp->left, value, replacementfromLefttoright);
        }
        else
        {
            // we found the node that we have to delete
            if (temp->left == nullptr and temp->right == nullptr)
            {
                delete temp;
                return nullptr;
            }
            // if it has only left child
            if (temp->left != nullptr and temp->right == nullptr)
            {
                Node *leftchild = temp->left;
                delete temp;
                return leftchild;
            }
            if (temp->left != nullptr and temp->right == nullptr)
            {
                Node *leftchild = temp->left;
                delete temp;
                return leftchild;
            }
            // if has only right child
            if (temp->right != nullptr and temp->left == nullptr)
            {
                Node *rightchild = temp->right;
                delete temp;
                return rightchild;
            }
            // if have both left and right child
            if (replacementfromLefttoright)
            {
                Node *maxNode = FindMax(temp->left);
                temp->value = maxNode->value;
                temp->left = deleteNode(temp->left, maxNode->value, replacementfromLefttoright);
            }
            else
            {
                Node *minNode = FindMin(temp->right);
                temp->value = minNode->value;
                temp->left = deleteNode(temp->right, minNode->value, replacementfromLefttoright);
            }
        }
        return temp;
    }

public:
    BST() : root(nullptr) {}

    void BuildTree()
    {
        int value;
        cout << "Enter elements to build the BST (enter -1 to stop): " << endl;
        cin >> value;
        while (value != -1)
        {
            root = buildTree(root, value);
            cin >> value;
        }
    }

    void levelOrderTraversal()
    {
        cout << "Level Order Traversal: " << endl;
        levelorder(root);
        cout << endl;
    }
    void Inorder()
    {
        cout << "Inorder Traversal ::: ";
        inorder(root);
        cout << endl;
    }
    void insert(int value)
    {
        root = buildTree(root, value);
    }
    void DeleteNode(int value, bool key = false)
    {
        root = deleteNode(root, value, key);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    BST bst;
    bst.BuildTree(); // from this we cannot add -1
    bst.levelOrderTraversal();
    bst.Inorder();
    bst.insert(-1); // we can insert -1  by this
    bst.levelOrderTraversal();
    bst.Inorder();
    bst.DeleteNode(9);
    bst.levelOrderTraversal();
    bst.Inorder();
    return EXIT_SUCCESS;
}
