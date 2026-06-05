class Solution {
public:
    int maxArea(vector<int>&h){
        int i=0;
        int j=h.size()-1;
        int maxArea=INT_MIN;
        while(i<j){
            int area=(min(h[i],h[j]))*(j-i);
            maxArea=max(maxArea,area);
            if(h[i]<h[j])i++;
            else j--;
        }
        return  maxArea;
    }
};
