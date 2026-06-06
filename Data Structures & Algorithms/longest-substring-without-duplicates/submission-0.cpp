class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int j = 0;
        unordered_map<char,int> m;
        int maxCount = 0;

        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            m[c]++;

            while(m[c] > 1) {
                m[s[j]]--;
                j++;
            }

            maxCount = max(maxCount, i - j + 1);
        }

        return maxCount;
    }
};