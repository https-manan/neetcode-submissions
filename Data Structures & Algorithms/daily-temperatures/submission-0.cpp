class Solution {
public:
    vector<int> dailyTemperatures(vector<int>&t){
        vector<int>ans;
        for(int i=0;i<t.size();i++){
            int count=0;
            int j=i+1;
            while(j<t.size()){
                count++;
                if(t[i]<t[j]){
                    ans.push_back(count);
                    break;
                }
                j++;
            }
            if(j==t.size())ans.push_back(0);
        }
        return ans;
    }
};
