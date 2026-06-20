class Solution {
public:
    int lastStoneWeight(vector<int>& s){
        priority_queue<int>maxQ;
        for(int n:s){
            maxQ.push(n);
        }
        while(maxQ.size()>1){
            int a=maxQ.top();maxQ.pop();
            int b=maxQ.top();maxQ.pop();
            if(a!=b) maxQ.push(a-b);
        }
        return maxQ.empty()?0:maxQ.top();
    }
};
