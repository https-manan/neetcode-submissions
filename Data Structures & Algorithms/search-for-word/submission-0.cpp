class Solution {
public:
    bool helper(vector<vector<char>>& b, string w, int i, int j, int m) {
        if (m == w.length()) return true;
        if (i < 0 || i >= b.size() || j < 0 || j >= b[0].size() || b[i][j] != w[m]) {
            return false;
        }
        char temp = b[i][j];
        b[i][j] = '*'; 
        bool found = helper(b, w, i + 1, j, m + 1) ||
                     helper(b, w, i, j + 1, m + 1) ||
                     helper(b, w, i - 1, j, m + 1) ||
                     helper(b, w, i, j - 1, m + 1);
        
        b[i][j] = temp;
        
        return found;
    }
    bool exist(vector<vector<char>>& b, string w) {
        for (int i = 0; i < b.size(); i++) {
            for (int j = 0; j < b[0].size(); j++) {
                if (b[i][j] == w[0]) {
                    if (helper(b, w, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};