class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums){
        int l;
        int r;
        vector<int>ans(nums.size());
        for(int i=0;i<nums.size();i++){
            l=1,r=1;
            for(int j=i+1;j<nums.size();j++){
                r*=nums[j];
            }
            for(int m=i-1;m>=0;m--){
                l*=nums[m];
            }
            ans[i]=l*r;
        }
        return ans;
    }
};
