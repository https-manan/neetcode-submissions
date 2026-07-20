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
    bool helper(TreeNode*l,TreeNode*r){
        if(!l&&!r)return true;
        if(!l||!r)return false;
        if(l->val!=r->val)return false;
        return helper(l->left,r->left)&&helper(l->right,r->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot){
        if (!subRoot) return true;
        if(!root)return false;
        if(root->val==subRoot->val && helper(root,subRoot)){
            return true;
        }
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};
