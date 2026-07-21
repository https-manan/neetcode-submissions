/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    bool rootToX(TreeNode* root, TreeNode* x, int maxInPath) {
        if (!root) return false;
        maxInPath = max(maxInPath, root->val);
        if (root == x) {
            return x->val >= maxInPath;
        }
        return rootToX(root->left, x, maxInPath) || 
               rootToX(root->right, x, maxInPath);
    }
    void helper(TreeNode* root, TreeNode* temp) {
        if (!temp) return;
        if (rootToX(root, temp, root->val)) ans++;
        helper(root, temp->left);
        helper(root, temp->right);
    }
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        TreeNode* temp = root;
        helper(root, temp);
        return ans;
    }
};