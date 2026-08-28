#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BST {
public:

    // Insert into BST
    Node* insert(Node* root, int val) {

        if (root == nullptr) {
            return new Node(val);
        }

        if (val < root->data) {
            root->left = insert(root->left, val);
        }
        else {
            root->right = insert(root->right, val);
        }

        return root;
    }


    // Largest element
    int largest(Node* root) {

        if (root == nullptr) {
            return -1;
        }

        while (root->right != nullptr) {
            root = root->right;
        }

        return root->data;
    }


    // 2nd largest element
    int secondLargest(Node* root) {

        int count = 0;
        int ans = -1;

        secondLargestUtil(root, count, ans);

        return ans;
    }

    void secondLargestUtil(Node* root, int& count, int& ans) {

        if (root == nullptr) {
            return;
        }

        // Reverse inorder: Right -> Root -> Left
        secondLargestUtil(root->right, count, ans);

        // Stop if answer already found
        if (count == 2) {
            return;
        }

        count++;

        if (count == 2) {
            ans = root->data;
            return;
        }

        secondLargestUtil(root->left, count, ans);
    }


    // Kth largest element
    int kthLargest(Node* root, int k) {

        int count = 0;
        int ans = -1;

        kthLargestUtil(root, k, count, ans);

        return ans;
    }

    void kthLargestUtil(Node* root, int k, int& count, int& ans) {

        if (root == nullptr) {
            return;
        }

        // Reverse inorder: Right -> Root -> Left
        kthLargestUtil(root->right, k, count, ans);

        if (count == k) {
            return;
        }

        count++;

        if (count == k) {
            ans = root->data;
            return;
        }

        kthLargestUtil(root->left, k, count, ans);
    }


    // Kth smallest element
    int kthSmallest(Node* root, int k) {

        int count = 0;
        int ans = -1;

        kthSmallestUtil(root, k, count, ans);

        return ans;
    }

    void kthSmallestUtil(Node* root, int k, int& count, int& ans) {

        if (root == nullptr) {
            return;
        }

        // Inorder: Left -> Root -> Right
        kthSmallestUtil(root->left, k, count, ans);

        if (count == k) {
            return;
        }

        count++;

        if (count == k) {
            ans = root->data;
            return;
        }

        kthSmallestUtil(root->right, k, count, ans);
    }
};


int main() {

    BST tree;

    Node* root = nullptr;

    root = tree.insert(root, 50);
    tree.insert(root, 30);
    tree.insert(root, 20);
    tree.insert(root, 40);
    tree.insert(root, 70);
    tree.insert(root, 60);
    tree.insert(root, 80);


    cout << "Largest: "
         << tree.largest(root) << endl;

    cout << "2nd Largest: "
         << tree.secondLargest(root) << endl;

    cout << "3rd Largest: "
         << tree.kthLargest(root, 3) << endl;

    cout << "3rd Smallest: "
         << tree.kthSmallest(root, 3) << endl;


    return 0;
}


/*

The main thing to remember
Kth Smallest → Left → Root → Right
Kth Largest  → Right → Root → Left


it's just inorder/reverse-inorder + counting.

*/