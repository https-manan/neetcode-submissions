class Solution {
public:
    int maxProfit(vector<int>& p){
        int maxy=0;
        for(int i=0;i<p.size()-1;i++){
            int buy=p[i];
            for(int j=i+1;j<p.size();j++){
                int profit=0;
                if(p[j]>buy){
                    profit=p[j]-buy;
                    maxy=max(maxy,profit);
                }else continue;
            }
        }
        return maxy;
    }
};
