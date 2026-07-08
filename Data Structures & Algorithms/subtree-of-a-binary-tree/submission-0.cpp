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
    bool isSame(TreeNode* r,TreeNode* s){
        if(!r&&!s)return true;
        if(!r||!s)return false;
        if(r->val!=s->val)return false;
        return isSame(r->left,s->left)&&isSame(r->right,s->right);
    }
    bool isSubtree(TreeNode* r, TreeNode* s){
        if(!r)return false;
        if(r->val==s->val){
            if(isSame(r,s))return true;
        }
        return isSubtree(r->left,s)||isSubtree(r->right,s);
    }
};
