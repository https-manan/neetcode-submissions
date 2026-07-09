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
    bool path(TreeNode* root, TreeNode* p,vector<TreeNode*>&ans){
        if(!root)return false;
        ans.push_back(root);
        if(root==p)return true;
        if(path(root->left,p,ans) || path(root->right,p,ans))return true;
        ans.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>ans1;
        vector<TreeNode*>ans2;
        path(root,p,ans1);
        path(root,q,ans2);
        int smaller=ans1.size()<ans2.size()?ans1.size():ans2.size();
        TreeNode*lca=NULL;
        for(int i=0;i<smaller;i++){
            if(ans1[i]==ans2[i])lca=ans1[i];
            else break;
        }
        return lca;
    }
};
