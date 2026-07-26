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
    int preIdx=0;
    unordered_map<int,int>m;
    TreeNode* build(vector<int>& pre,int l,int r){
        if(l>r)return NULL;
        int rootVal=pre[preIdx++];
        TreeNode*root=new TreeNode(rootVal);
        int mid=m[rootVal];
        root->left=build(pre,l,mid-1);
        root->right=build(pre,mid+1,r);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        for(int i=0;i<in.size();i++){
            m[in[i]]=i;
        }
        return build(pre,0,in.size()-1);
    }
};
