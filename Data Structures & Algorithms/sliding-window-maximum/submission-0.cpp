class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int i=0;
        int j=k;
        while(j<=nums.size()){
            priority_queue<int>q;
            for(int m=i;m<j;m++){
                q.push(nums[m]);
            }
            ans.push_back(q.top());
            i++,j++;
        }
        return ans;
    }
};
