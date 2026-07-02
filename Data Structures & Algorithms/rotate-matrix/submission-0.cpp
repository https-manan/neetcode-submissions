class Solution {
public:
    void rotate(vector<vector<int>>& g){
        int n=g.size();
        int m=g[0].size();
        for(int i=0;i<n/2;i++){
            for(int j=0;j<m;j++){
                swap(g[i][j],g[n-i-1][j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(g[i][j],g[j][i]);
            }
        }
    }
};