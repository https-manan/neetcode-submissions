class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>maxQ;
    int k=0;
    KthLargest(int k, vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            maxQ.push(nums[i]);
        }
        this->k=k;
    }
    int add(int val){
        maxQ.push(val);
        while(maxQ.size()>k)maxQ.pop();
        return maxQ.top();
    }
};
