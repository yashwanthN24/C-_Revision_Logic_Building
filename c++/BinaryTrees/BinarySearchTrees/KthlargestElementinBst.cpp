#include <iostream>
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

class BST {
private:
    Node* root;

    // Insert
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

    // Kth Smallest: Left -> Root -> Right
    void kthSmallest(Node* root, int k, int& count, int& ans) {
        if (root == nullptr || count >= k)
            return;

        // Left
        kthSmallest(root->left, k, count, ans);

        // Root
        count++;

        if (count == k) {
            ans = root->data;
            return;
        }

        // Right
        kthSmallest(root->right, k, count, ans);
    }

    // Kth Largest: Right -> Root -> Left
    void kthLargest(Node* root, int k, int& count, int& ans) {
        if (root == nullptr || count >= k)
            return;

        // Right
        kthLargest(root->right, k, count, ans);

        // Root
        count++;

        if (count == k) {
            ans = root->data;
            return;
        }

        // Left
        kthLargest(root->left, k, count, ans);
    }

public:

    BST() {
        root = nullptr;
    }

    // Public insert
    void insert(int val) {
        root = insert(root, val);
    }

    // Kth Smallest
    int getKthSmallest(int k) {
        int count = 0;
        int ans = -1;

        kthSmallest(root, k, count, ans);

        return ans;
    }

    // Kth Largest
    int getKthLargest(int k) {
        int count = 0;
        int ans = -1;

        kthLargest(root, k, count, ans);

        return ans;
    }

    // Largest = 1st largest
    int getLargest() {
        return getKthLargest(1);
    }

    // 2nd Largest
    int getSecondLargest() {
        return getKthLargest(2);
    }
};

int main() {

    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    /*
              50
             /  \
           30    70
          / \    / \
        20  40  60  80
    */

    cout << "Largest: "
         << tree.getLargest() << endl;

    cout << "2nd Largest: "
         << tree.getSecondLargest() << endl;

    int k = 3;

    cout << k << "th Largest: "
         << tree.getKthLargest(k) << endl;

    cout << k << "th Smallest: "
         << tree.getKthSmallest(k) << endl;

    return 0;
} 