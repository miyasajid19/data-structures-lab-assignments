#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int value;
    Node *left, *right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

class BST {
    Node *root;

    Node *BuildTree(Node *temp, int value) {
        if (temp == nullptr)
            return new Node(value);

        if (value < temp->value)
            temp->left = BuildTree(temp->left, value);
        else
            temp->right = BuildTree(temp->right, value);

        return temp;
    }

    void inorder(Node *temp) {
        if (temp == nullptr)
            return;

        inorder(temp->left);
        cout << temp->value << "\t";
        inorder(temp->right);
    }

    int Findmin(Node *temp) {
        if (temp == nullptr)
            return -1;

        while (temp->left != nullptr)
            temp = temp->left;
        return temp->value;
    }

    int Findmax(Node *temp) {
        if (temp == nullptr)
            return -1;

        while (temp->right != nullptr)
            temp = temp->right;
        return temp->value;
    }

public:
    BST() : root(nullptr) {}

    void buildTree(int value) {
        root = BuildTree(root, value);
    }

    void InorderTraversal() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    int minValue() {
        return Findmin(root);
    }

    pair<int, int> predessorSuccessor(int key) {
        Node *temp = root;
        int predecessor = -1, successor = -1;

        // Traverse to find the node
        while (temp != nullptr) {
            if (key > temp->value) {
                predecessor = temp->value;
                temp = temp->right;
            } else if (key < temp->value) {
                successor = temp->value;
                temp = temp->left;
            } else {
                break;
            }
        }

        if (temp == nullptr)
            return make_pair(-1, -1); // Key not found

        // Find predecessor: max in left subtree
        if (temp->left != nullptr)
            predecessor = Findmax(temp->left);

        // Find successor: min in right subtree
        if (temp->right != nullptr)
            successor = Findmin(temp->right);

        return make_pair(predecessor, successor);
    }
};

int main() {
#ifndef JUDGE_ONLINE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    BST bst;
    int n, value;

    cout << "How many data do you have? ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        bst.buildTree(value);
    }
    cout << endl;

    bst.InorderTraversal();

    cout << "Minimum Element in BST: " << bst.minValue() << endl;

    int key = 6;
    pair<int, int> predecessor_successor = bst.predessorSuccessor(key);
    cout << "Inorder Predecessor of " << key << ": " << predecessor_successor.first << endl;
    cout << "Inorder Successor of " << key << ": " << predecessor_successor.second << endl;

    return EXIT_SUCCESS;
}
