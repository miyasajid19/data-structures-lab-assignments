#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
    Node *root;

    // Helper function to perform inorder traversal of the tree
    void Inorder(Node *temp)
    {
        if (temp == nullptr)
            return;
        Inorder(temp->left);
        cout << temp->value << "\t";
        Inorder(temp->right);
    }

    void preorder(Node *temp)
    {
        if (temp == nullptr)
            return;
        cout << temp->value << "\t";
        Inorder(temp->left);
        Inorder(temp->right);
    }

    void postorder(Node *temp)
    {
        if (temp == nullptr)
            return;
        Inorder(temp->left);
        Inorder(temp->right);
        cout << temp->value << "\t";
    }

    // Recursive function to build the tree from inorder and preorder
    Node *Inorder_Preorder(vector<int> &inorder, vector<int> &preorder, int &preorderIndex, int inorderStart, int inorderEnd, unordered_map<int, int> &inorderMapping)
    {
        // Base case: if the start index is greater than end index, return nullptr
        if (inorderStart > inorderEnd)
            return nullptr;

        // Get the root value from the preorder array
        int val = preorder[preorderIndex];
        Node *node = new Node(val);

        // Increment preorderIndex for next root value
        preorderIndex++;

        // Find the index of the root in inorder traversal
        int inorderIndex = inorderMapping[val];

        // Recursively build the left subtree and right subtree
        node->left = Inorder_Preorder(inorder, preorder, preorderIndex, inorderStart, inorderIndex - 1, inorderMapping);
        node->right = Inorder_Preorder(inorder, preorder, preorderIndex, inorderIndex + 1, inorderEnd, inorderMapping);

        return node;
    }

public:
    BinaryTree(vector<int> &inorder, vector<int> &preorder)
    {
        if (inorder.size() != preorder.size())
            exit(0);

        unordered_map<int, int> inorderMapping;
        // Map each value in inorder to its index for fast lookup
        for (int i = 0; i < inorder.size(); i++)
            inorderMapping[inorder[i]] = i;

        int preorderIndex = 0;
        root = Inorder_Preorder(inorder, preorder, preorderIndex, 0, inorder.size() - 1, inorderMapping);
    }

    void InorderTraversal()
    {
        cout << "Inorder Traversal :: ";
        Inorder(root);
        cout << endl;
    }
    void PreorderTraversal()
    {
        cout << "Preorder Traversal :: ";
        preorder(root);
        cout << endl;
    }
    void postorderTraversal()
    {
        cout << "Posrorder Traversal :: ";
        postorder(root);
        cout << endl;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // Test case
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};

    BinaryTree tree(inorder, preorder);

    // Print inorder traversal of the constructed BinaryTree
    tree.InorderTraversal();
    tree.postorderTraversal();
    tree.PreorderTraversal();

    cout << endl;

    return EXIT_SUCCESS;
}
