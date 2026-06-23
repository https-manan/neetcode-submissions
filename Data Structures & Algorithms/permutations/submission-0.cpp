class Solution {
public:
    vector<vector<int>> ans;

    void helper(vector<int>& nums, vector<int>& temp, int i) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int j = 0; j < nums.size(); j++) {

            bool used = false;
            for (int k = 0; k < temp.size(); k++) {
                if (temp[k] == nums[j]) {
                    used = true;
                    break;
                }
            }

            if (used) continue;

            temp.push_back(nums[j]);
            helper(nums, temp, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        helper(nums, temp, 0);
        return ans;
    }
};