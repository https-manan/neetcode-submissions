class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k){
        vector<int>ans;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<pair<int,int>>ve(m.begin(),m.end());
        sort(ve.begin(),ve.end(),[](const auto &a,const auto &b){
            return a.second>b.second;
        });
        for(int i=0;i<k;i++){
            ans.push_back(ve[i].first);
        }
        return ans;
    }
};


//simply what we gonna  do is make a map and store number and freq and in end sort on basis of 2nd number and then return top k
