class Solution {
public:
    int longestConsecutive(vector<int>& nums){
        if(nums.empty())return 0;
        sort(nums.begin(),nums.end());
        int smallest=nums[0];
        int count=1;
        int ans=1;
        for(int i=1;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            if(nums[i]==smallest+1){
                count++;
                smallest=nums[i];
            }else{
                ans=max(ans,count);
                count=1;
                smallest=nums[i];
            }
        }
        ans=max(ans,count);
        return ans;
    }
};
