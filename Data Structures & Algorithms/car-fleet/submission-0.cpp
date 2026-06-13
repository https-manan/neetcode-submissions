class Solution {
public:
    int carFleet(int t, vector<int>& pos, vector<int>& speed) {
        vector<pair<int, int>> v;
        int n = pos.size();
        for (int i = 0; i < n; i++) {
            v.push_back({pos[i], speed[i]});
        }
        sort(v.begin(), v.end());
        stack<double> st;
        for (int i = n - 1; i >= 0; i--) {
            double time = (double)(t - v[i].first) / v[i].second;
            if (st.empty() || time > st.top()) {
                st.push(time);
            }
        }

        return st.size();
    }
};