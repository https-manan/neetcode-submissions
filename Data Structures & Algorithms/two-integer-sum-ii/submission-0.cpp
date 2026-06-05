class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        for(int i = 0; i <= n.size() - 2; i++) {
            for(int j = i + 1; j <= n.size() - 1; j++) {
                if(n[i] + n[j] == t) {
                    return {i + 1, j + 1};
                }
            }
        }
        return {};
    }
};