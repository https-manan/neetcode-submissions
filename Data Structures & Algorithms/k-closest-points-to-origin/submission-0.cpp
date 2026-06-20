class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>>q;
        
        for(int i = 0; i < p.size(); i++){
            int x = p[i][0];
            int y = p[i][1];
            int dis = x * x + y * y;
            q.push({dis, {x, y}});
        }
        vector<vector<int>> ans;
        while (k-- && !q.empty()) {
            auto it = q.top();
            q.pop();
            ans.push_back({it.second.first, it.second.second});
        }
        return ans;
    }
};