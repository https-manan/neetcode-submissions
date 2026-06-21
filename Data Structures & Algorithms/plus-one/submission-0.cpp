class Solution {
public:
    vector<int> plusOne(vector<int>& dig) {
        long long a = 0;

        for (int i : dig) {
            a = a * 10 + i;   // build the number correctly
        }

        a += 1;

        vector<int> ans;

        while (a > 0) {
            ans.push_back(a % 10);
            a /= 10;
        }

        reverse(ans.begin(), ans.end()); 
        return ans;
    }
};