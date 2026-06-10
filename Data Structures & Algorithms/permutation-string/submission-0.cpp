class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        if(n>m)return false;
        int i=0;
        int j=n-1;
        vector<int>ansFreq(26,0);
        for(char c:s1){
            ansFreq[c-'a']++;
        }
        while(j<m){
            vector<int>testFreq(26,0);
            for(int k=i;k<=j;k++){
                testFreq[s2[k]-'a']++;
            }
            bool same=true;
            for(int z=0;z<26;z++){
                if(ansFreq[z]!=testFreq[z]){
                    same=false;
                    break;
                }
            }
            if(same)return true;
            i++;
            j++;
        }
        return false;
    }
};
