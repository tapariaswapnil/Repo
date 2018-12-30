// C++ program to Check given array
// can represent BST or not
#include <bits/stdc++.h>
using namespace std;

// structure for Binary Node
struct Node {
    int key;
    struct Node *right, *left;
};

Node* newNode(int num)
{
    Node* temp = new Node;
    temp->key = num;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// To create a Tree with n levels. We always
// insert new node to left if it is less than
// previous value.
Node* createNLevelTree(int arr[], int n)
{
    Node* root = newNode(arr[0]);
    Node* temp = root;
    for (int i = 1; i < n; i++) {
        if (temp->key > arr[i]) {
            temp->left = newNode(arr[i]);
            temp = temp->left;
        }
        else {
            temp->right = newNode(arr[i]);
            temp = temp->right;
        }
    }
    return root;
}

// Please refer below post for details of this
// function.
// https:// www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
bool isBST(Node* root, int min, int max)
{
    if (root == NULL)
        return true;

    if (root->key < min || root->key > max)
        return false;

    // Allow only distinct values
    return (isBST(root->left, min,
                  (root->key) - 1)
            && isBST(root->right,
                     (root->key) + 1, max));
}

// Returns tree if given array of size n can
// represent a BST of n levels.
bool canRepresentNLevelBST(int arr[], int n)
{
    Node* root = createNLevelTree(arr, n);
    return isBST(root, INT_MIN, INT_MAX);
}

// Driver code
int main()
{
    int arr[] = { 512, 330, 78, 11, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);

    if (canRepresentNLevelBST(arr, n))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
