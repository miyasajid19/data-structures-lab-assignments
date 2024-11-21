#include <iostream>
#include <cstdlib>
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
class BST
{
    Node *head;
    Node *BuildTree(Node *temp, int value)
    {
        if (temp == nullptr)
        {
            return new Node(value);
        }
        if (temp->value > value)
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
    void postorder(Node *temp)
    {
        if (temp == nullptr)
            return;

        inorder(temp->left);
        inorder(temp->right);
        cout << temp->value << "\t";
    }
    void preorder(Node *temp)
    {
        if (temp == nullptr)
            return;

        cout << temp->value << "\t";
        inorder(temp->left);
        inorder(temp->right);
    }

public:
    BST()
    {
        this->head = nullptr;
    }
    void buildTree()
    {
        int value;
        cout << "enter value of node :: " << endl;
        cin >> value;
        if (value != -1)
            head = BuildTree(head, value);
    }
    void InorderTraversal()
    {
        cout << "inorder Traversal :: ";
        inorder(head);
        cout << endl;
    }
    void PreOrderTraversal()
    {
        cout << "preorder Traversal :: ";
        preorder(head);
        cout << endl;
    }
    void PostOrderTraversal()
    {
        cout << "postorder Traversal :: ";
        postorder(head);
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
    int n;
    cout << "How many data do you have??" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        bst.buildTree();
    }
    bst.PreOrderTraversal();
    bst.InorderTraversal();
    bst.PostOrderTraversal();
    return EXIT_SUCCESS;
}