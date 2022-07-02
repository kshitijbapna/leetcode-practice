class Solution {
public:
    int maxArea(int h, int w, vector<int>& hC, vector<int>& vC) {
        hC.push_back(0);
        vC.push_back(0);
        hC.push_back(h);
        vC.push_back(w);
        sort(hC.begin(),hC.end());
        sort(vC.begin(),vC.end());
        long long mxh=0,mxv=0;
        for(int i=1;i<hC.size();i++){
            mxh=max(mxh,(long long)hC[i]-hC[i-1]);
        }
        for(int i=1;i<vC.size();i++){
            mxv=max(mxv,(long long)vC[i]-vC[i-1]);
        }
        return (mxh*mxv)%(int)(1e9+7);
    }
};