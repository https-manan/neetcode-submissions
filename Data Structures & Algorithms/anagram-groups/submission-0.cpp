class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(string s:strs){
            vector<int>m(26,0);
            for(char c:s){
                m[c-'a']++;
            }
            string key="";
            for(int i=0;i<26;i++){
                key+=to_string(m[i])+"-";
            }
            mp[key].push_back(s);
        }
        for(auto &p : mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};
