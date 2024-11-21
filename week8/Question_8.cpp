#include <iostream>
#include <queue>
#include <vector>
#include <algorithm> // For std::merge
using namespace std;

class Node
{
public:
    int value;
    Node *left;  // used for DLL previous pointer
    Node *right; // used for DLL next pointer
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

class BST
{
    Node *root;

    // Recursive function to build the tree
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

    // In-order traversal to collect values into an array
    void inorder(Node *temp, vector<int> &values)
    {
        if (temp == nullptr)
            return;
        inorder(temp->left, values);
        values.push_back(temp->value);
        inorder(temp->right, values);
    }

    // Convert BST to Doubly Linked List using In-Order Traversal
    void BSTtoDLL(Node *root, Node *&head, Node *&prev)
    {
        // Base case
        if (root == nullptr)
            return;

        // Recursively convert the left subtree
        BSTtoDLL(root->left, head, prev);

        // Convert the current node
        if (prev == nullptr)
        {
            // This is the first node, so it becomes the head of the DLL
            head = root;
        }
        else
        {
            // Set the current node's left (previous pointer) to 'prev'
            prev->right = root;
            root->left = prev;
        }
        prev = root; // Move 'prev' to the current node

        // Recursively convert the right subtree
        BSTtoDLL(root->right, head, prev);
    }

    // Function to create a balanced BST from a sorted array
    Node *sortedArrayToBST(const vector<int> &values, int start, int end)
    {
        if (start > end)
            return nullptr;

        int mid = start + (end - start) / 2;
        Node *node = new Node(values[mid]);

        node->left = sortedArrayToBST(values, start, mid - 1);
        node->right = sortedArrayToBST(values, mid + 1, end);

        return node;
    }

public:
    BST() : root(nullptr) {}

    // Build the tree by inserting elements
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

    // In-order traversal to print the BST
    void Inorder()
    {
        cout << "Inorder Traversal of BST: ";
        vector<int> values;
        inorder(root, values);
        for (int val : values)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    // Merge another BST into this one
    void mergeTree(BST &bst2)
    {
        // Step 1: Get in-order traversal of both trees
        vector<int> values1, values2;
        inorder(this->root, values1);
        inorder(bst2.root, values2);

        // Step 2: Merge the two sorted arrays
        vector<int> mergedValues(values1.size() + values2.size());
        merge(values1.begin(), values1.end(), values2.begin(), values2.end(), mergedValues.begin());

        // Step 3: Rebuild the BST from the merged array
        this->root = sortedArrayToBST(mergedValues, 0, mergedValues.size() - 1);
    }

    // Convert the BST to Doubly Linked List (DLL)
    Node* BSTToDLL()
    {
        Node *head = nullptr, *prev = nullptr;
        BSTtoDLL(root, head, prev);
        return head; // Return the head of the DLL
    }

    // Print the DLL
    void PrintDLL(Node *head)
    {
        Node *temp = head;
        cout << "Doubly Linked List: ";
        cout <<nullptr<<" <----> ";
        while (temp != nullptr)
        {
            cout << temp->value << " <----> ";
            temp = temp->right; // move to next node in DLL
        }
        cout <<nullptr<< endl;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    BST bst1, bst2;
    bst1.BuildTree();
    bst2.BuildTree();
    bst1.Inorder();
    bst2.Inorder();
    bst1.mergeTree(bst2);
    bst1.Inorder();

    // Convert merged BST into Doubly Linked List and print it
    Node *dllHead = bst1.BSTToDLL();
    bst1.PrintDLL(dllHead);

    return EXIT_SUCCESS;
}
