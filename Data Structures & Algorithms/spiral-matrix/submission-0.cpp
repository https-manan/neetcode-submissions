class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m){
        vector<int>ans;
        int sr=0,sc=0,er=m.size()-1,ec=m[0].size()-1;
        while(sr<=er&&sc<=ec){
             for (int j = sc; j <= ec; j++)
                ans.push_back(m[sr][j]);
            for (int i = sr + 1; i <= er; i++)
                ans.push_back(m[i][ec]);
            if (sr < er) {
                for (int j = ec - 1; j >= sc; j--)
                    ans.push_back(m[er][j]);
            }
            if (sc < ec) {
                for (int i = er - 1; i > sr; i--)
                    ans.push_back(m[i][sc]);
            }
            sc++,sr++,ec--,er--;
        }
        return ans;
    }
};
