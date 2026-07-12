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
    vector<int> rightSideView(TreeNode* root){
        if (!root) return {};
        queue<pair<TreeNode*,int>>q;
        map<int,int>m;
        q.push({root,0});

        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto p=q.front();
                q.pop();
                m[p.second]=p.first->val;
                if(p.first->left) q.push({p.first->left, p.second + 1});
                if(p.first->right) q.push({p.first->right, p.second + 1});
            }
        }
        vector<int>ans;
        for(auto i:m){
            ans.push_back(i.second);
        } 
        return ans;
    }
};