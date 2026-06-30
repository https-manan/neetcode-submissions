class Solution {
public: 
    vector<string>ans;
    void helper(int n, int open, int close,vector<string>& temp){
        if(temp.size()==2*n){
            string s = "";
            for (auto &x : temp) s += x;
            ans.push_back(s);
            return;
        }
        if (open < n) {
            temp.push_back("(");
            helper(n, open + 1, close, temp);
            temp.pop_back();
        }

        if (close < open) {
            temp.push_back(")");
            helper(n, open, close + 1, temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n){
        vector<string>temp;
        helper(n,0,0,temp);
        return ans;
    }
};
