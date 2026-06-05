class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> Lmax(n);
        vector<int> Rmax(n);
        int water = 0;
        int mtn = 0;
        for (int i=0;i<n;i++) {
            mtn = max(mtn, h[i]);
            Lmax[i] = mtn;
        }
        mtn = 0;
        for (int i=n-1;i>=0;i--) {
            mtn = max(mtn,h[i]);
            Rmax[i] =mtn;
        }
        for (int i=0;i<n;i++) {
            water += min(Lmax[i],Rmax[i])-h[i];
        }
        return water;
    }
};