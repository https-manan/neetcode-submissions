class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int a=0;a<n-2;a++){
            if(a>0 && nums[a]==nums[a-1])continue;
            int b=a+1,c=n-1;
            while(b<c){
                if(nums[a]+nums[b]+nums[c]==0){
                    ans.push_back({nums[a],nums[b],nums[c]});
                    b++,c--;
                    while(b<c && nums[b-1]==nums[b])b++;
                    while(c>b && nums[c]==nums[c+1])c--;
                }else if(nums[a]+nums[b]+nums[c]<0){
                    b++;
                }else{
                    c--;
                }
            }
        }
        return ans;
    }
};