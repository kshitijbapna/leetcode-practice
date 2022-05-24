class Solution {
public:
    int minimumLines(vector<vector<int>>& s) {
        int n=s.size();
        if(n==1)return 0;
        sort(s.begin(),s.end());
        long long prevy=s[1][1]-s[0][1],prevx=s[1][0]-s[0][0];
        int ans=1;
        for(int i=2;i<n;i++){
            long long curry=s[i][1]-s[i-1][1],currx=s[i][0]-s[i-1][0];
            if(currx*prevy!=curry*prevx)ans++;
            prevx=currx;
            prevy=curry;
        }
        return ans;
    }
};