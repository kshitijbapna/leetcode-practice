class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        vector<int> sum(n);
        sum[0]=cardPoints[0];
        for(int i=1;i<n;i++){
            sum[i]+=cardPoints[i]+sum[i-1];
        }
        if(k==n)return sum[n-1];
        int ans=0;
        for(int i=0;i<=k;i++){
            int y;
            if(i==0){
                y=sum[n-1]-sum[n-k-1];
            }
            else if(i==k){
                y=sum[i-1];
            }
            else{
                y=sum[i-1]+sum[n-1]-sum[n-k+i-1];
            }
            ans=max(ans,y);
        }
        return ans;
    }
};