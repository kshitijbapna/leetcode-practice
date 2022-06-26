class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        for(int i=1;i<n;i++){
            cardPoints[i]+=cardPoints[i-1];
        }
        if(k==n)return cardPoints[n-1];
        int ans=0;
        for(int i=0;i<=k;i++){
            int y;
            if(i==0){
                y=cardPoints[n-1]-cardPoints[n-k-1];
            }
            else if(i==k){
                y=cardPoints[i-1];
            }
            else{
                y=cardPoints[i-1]+cardPoints[n-1]-cardPoints[n-k+i-1];
            }
            ans=max(ans,y);
        }
        return ans;
    }
};