#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int value;
    Node *left;
    Node *right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

class BST {
    Node *root;

    void levelorder(Node *temp) {
        if (temp == nullptr) {
            cout << "Tree is empty." << endl;
            return;
        }

        queue<Node *> Queue;
        int level = 0;
        cout << "Level " << level << " :: ";
        Queue.push(temp);
        Queue.push(nullptr); // Marker for level separation

        while (!Queue.empty()) {
            Node *TopNode = Queue.front();
            Queue.pop();

            if (TopNode == nullptr) {
                cout << endl;
                level++;
                if (!Queue.empty()) {
                    cout << "Level " << level << " :: ";
                    Queue.push(nullptr); // Add marker for next level
                }
            } else {
                cout << TopNode->value << '\t';
                if (TopNode->left)
                    Queue.push(TopNode->left);
                if (TopNode->right)
                    Queue.push(TopNode->right);
            }
        }
    }

    Node *buildTree(Node *temp, int value) {
        if (temp == nullptr)
            return new Node(value);

        if (value > temp->value)
            temp->right = buildTree(temp->right, value);
        else if (value < temp->value)
            temp->left = buildTree(temp->left, value);

        return temp;
    }

public:
    BST() : root(nullptr) {}

    void BuildTree() {
        int value;
        cout << "Enter elements to build the BST (enter -1 to stop): " << endl;
        cin >> value;
        while (value != -1) {
            root = buildTree(root, value);
            cin >> value;
        }
    }

    void levelOrderTraversal() {
        cout << "Level Order Traversal: " << endl;
        levelorder(root);
        cout << endl;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    BST bst;
    bst.BuildTree();
    bst.levelOrderTraversal();

    return EXIT_SUCCESS;
}
