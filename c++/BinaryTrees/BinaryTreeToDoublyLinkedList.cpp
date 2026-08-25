#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    Node* prev = nullptr;
    Node* head = nullptr;

    void convert(Node* root) {

        if (root == nullptr)
            return;

        // Left
        convert(root->left);

        // Current node
        if (prev == nullptr) {
            // First node of DLL
            head = root;
            root->left = nullptr;
        }
        else {
            // Connect previous and current
            prev->right = root;
            root->left = prev;
        }

        prev = root;

        // Right
        convert(root->right);
    }

    Node* bToDLL(Node* root) {
        prev = nullptr;
        head = nullptr;

        convert(root);

        // Last node
        if (prev != nullptr)
            prev->right = nullptr;

        return head;
    }
};

int main() {

    // Creating Binary Tree
    //
    //          4
    //        /   \
    //       2     5
    //      / \
    //     1   3

    Node* root = new Node(4);

    root->left = new Node(2);
    root->right = new Node(5);

    root->left->left = new Node(1);
    root->left->right = new Node(3);

    Solution obj;

    // Convert Binary Tree to DLL
    Node* head = obj.bToDLL(root);

    // Print DLL
    cout << "DLL: ";

    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->right;
    }

    // so right becomes next and left becomes prev 

    cout << endl;

    return 0;
}