class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& nums, int t,vector<int>& temp,int sum,int i){
        if (sum == t){
            ans.push_back(temp);
            return;
        }
        if(i==nums.size()||sum>t)return;
        temp.push_back(nums[i]);
        helper(nums, t, temp, sum + nums[i],i);
        temp.pop_back();
        helper(nums, t, temp, sum, i + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        helper(nums, target, temp, 0, 0);
        return ans;
    }
};