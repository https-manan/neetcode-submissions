class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;

        for (char c : tasks) {
            mp[c]++;
        }

        int ans = 0;

        while (true) {
            vector<pair<char, int>> v(mp.begin(), mp.end());

            sort(v.begin(), v.end(),
                 [](const auto& a, const auto& b) {
                     return a.second > b.second;
                 });

            int done = 0;

            for (int i = 0; i <= n && i < (int)v.size(); i++) {
                if (v[i].second > 0) {
                    mp[v[i].first]--;
                    done++;
                }
            }

            bool finished = true;

            for (auto& p : mp) {
                if (p.second > 0) {
                    finished = false;
                    break;
                }
            }

            if (finished) {
                ans += done;
                break;
            }

            ans += (n + 1);
        }

        return ans;
    }
};