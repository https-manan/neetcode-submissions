class Solution {
public:
    int calTime(vector<int>&piles,int speed){
        int hrs=0;
        for(int pile:piles){
            hrs+=(pile+speed-1)/speed;
        }
        return hrs;
    }
    int minEatingSpeed(vector<int>& piles, int h){
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        while(l<r){
            int m=(l+r)/2;
            int hrs=calTime(piles,m);
            if(hrs<=h){
                r=m;
            }else{
                l=m+1;
            }
        }
        return l;
    }
};