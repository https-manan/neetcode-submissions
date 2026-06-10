class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int i=0;
        int j=0;
        int maxFreq=0;
        int ans=0;
        while(j<s.size()){
            char c=s[j];
            freq[c-'A']++;
            maxFreq=max(maxFreq,freq[c-'A']);
            while((j-i+1)-maxFreq>k){
                freq[s[i]-'A']--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
