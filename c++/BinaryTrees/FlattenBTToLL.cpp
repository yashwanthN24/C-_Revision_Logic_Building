/*

114. Flatten Binary Tree to Linked List
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 


https://chatgpt.com/c/6a8c985c-dbe8-83ee-bcb0-e72b055d6d81


*/


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr){
            return ;
        }

        TreeNode* curr = root;

        while(curr){

            // if tree has left node
            if(curr->left){

                TreeNode* pre = curr->left;
                // find the right most node in this left subtree 
                while(pre->right){
                    pre = pre->right;
                }

                // make this right nodes right point to curr nodes right 
                pre->right = curr->right;

                // make curr nodes right pont to left and make curr left to null
                curr->right = curr->left;

                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};