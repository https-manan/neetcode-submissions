class Solution {
public:
    vector<vector<int>> ans;

    void helper(vector<int>& nums, int target,
                vector<int>& temp, int start) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < nums.size(); i++) {

            // Skip duplicates at the same level
            if (i > start && nums[i] == nums[i - 1])
                continue;

            if (nums[i] > target)
                break;

            temp.push_back(nums[i]);
            helper(nums, target - nums[i], temp, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> temp;
        helper(candidates, target, temp, 0);

        return ans;
    }
};