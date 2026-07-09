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
    int helper(TreeNode* r){
        if(!r)return 0;
        int l=helper(r->left)+1;
        int rr=helper(r->right)+1;
        return max(l,rr);
    }
    int diameterOfBinaryTree(TreeNode* root){
        if(!root)return 0;
        int l=helper(root->left);
        int r=helper(root->right);
        return max(max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)),l+r);
    }
};
