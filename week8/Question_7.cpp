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

    // Helper function to perform preorder traversal of the tree
    void preorder(Node *temp)
    {
        if (temp == nullptr)
            return;
        cout << temp->value << "\t";
        preorder(temp->left);  // Corrected to preorder instead of Inorder
        preorder(temp->right); // Corrected to preorder instead of Inorder
    }

    // Helper function to perform postorder traversal of the tree
    void postorder(Node *temp)
    {
        if (temp == nullptr)
            return;
        postorder(temp->left);  // Corrected to postorder instead of Inorder
        postorder(temp->right); // Corrected to postorder instead of Inorder
        cout << temp->value << "\t";
    }

    // Recursive function to build the tree from inorder and postorder
    Node *Inorder_postorder(vector<int> &inorder, vector<int> &postorder, int &postorderIndex, int inorderStart, int inorderEnd, unordered_map<int, int> &inorderMapping)
    {
        // Base case: if the start index is greater than end index, return nullptr
        if (inorderStart > inorderEnd)
            return nullptr;

        // Get the root value from the postorder array
        int val = postorder[postorderIndex];
        Node *node = new Node(val);

        // Increment postorderIndex for next root value
        postorderIndex--;

        // Find the index of the root in inorder traversal
        int inorderIndex = inorderMapping[val];

        // Recursively build the left subtree and right subtree
        node->right = Inorder_postorder(inorder, postorder, postorderIndex, inorderIndex + 1, inorderEnd, inorderMapping);
        node->left = Inorder_postorder(inorder, postorder, postorderIndex, inorderStart, inorderIndex - 1, inorderMapping);

        return node;
    }

public:
    BinaryTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() != postorder.size())
            exit(0);

        unordered_map<int, int> inorderMapping;
        // Map each value in inorder to its index for fast lookup
        for (int i = 0; i < inorder.size(); i++)
            inorderMapping[inorder[i]] = i;

        int postorderIndex = postorder.size() - 1;
        root = Inorder_postorder(inorder, postorder, postorderIndex, 0, inorder.size() - 1, inorderMapping);
    }

    void InorderTraversal()
    {
        cout << "Inorder Traversal :: ";
        Inorder(root);
        cout << endl;
    }

    void preorderTraversal()  // Corrected function name to "preorderTraversal"
    {
        cout << "Preorder Traversal :: ";  // Corrected output string
        preorder(root);
        cout << endl;
    }

    void postorderTraversal()
    {
        cout << "Postorder Traversal :: ";  // Corrected output string
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
    vector<int> postorder = {3, 9, 20, 15, 7};

    BinaryTree tree(inorder, postorder);

    // Print inorder traversal of the constructed BinaryTree
    tree.InorderTraversal();
    tree.preorderTraversal();  // Corrected function call
    tree.postorderTraversal();

    cout << endl;

    return EXIT_SUCCESS;
}
