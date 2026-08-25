#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method to check if a unique binary tree can be constructed
    bool uniqueBinaryTree(int a, int b) {
        // Return false if both traversals are the same 
        // or if they are preorder and postorder
        return !(a == b || (a == 1 && b == 3) || (a == 3 && b == 1));
    }
};

// if not preorder and posoreder sequence in rst all cases we get unique binary tree 

// i.e preorder + inorder , postorder + inorder (we get unique binary tree)

// given preorder + postorder we can build binarty tree but never unique binary tree 

// but preorder /postorder /inorder wih markers allows to build unique tree always (markers liek -1 for null)

// for bst this differe because it has ordering property so any order works preorder only /postorde only / inorder only 

// but given inorder sequence we cant build unique bst as evry bst has the sqme sorted sequence so obsuoly not uniqe bst 

// so mostly we use preorder /psotordeer for building bst 

// normal insert method hat works for all using ordering property
