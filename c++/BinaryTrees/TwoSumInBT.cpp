#include  <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool dfs(TreeNode* root, int k, unordered_set<int>& seen) {
        if (!root) return false;

        if (seen.count(k - root->val))
            return true;

        seen.insert(root->val);

        return dfs(root->left, k, seen) ||
               dfs(root->right, k, seen);
    }

    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return dfs(root, k, seen);
    }
};