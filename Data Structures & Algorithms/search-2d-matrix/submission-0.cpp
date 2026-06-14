class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        int scol=m[0].size()-1;
        int srow=0;
        while(scol>=0&&srow<m.size()){
            if(m[srow][scol]==t)return true;
            if(m[srow][scol]>t){
                scol--;
            }else{
                srow++;
            }
        }
        return false;
    }
};
