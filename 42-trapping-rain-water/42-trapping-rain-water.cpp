class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0,n=height.size();
        vector<int> max_before(n),max_after(n);
        max_before[0]=0;
        max_after[n-1]=0;
        for(int i=1;i<n;i++){
            max_before[i]=max(max_before[i-1],height[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            max_after[i]=max(max_after[i+1],height[i+1]);
        }
        for(int i=1;i<n-1;i++){
            int k=min(max_before[i],max_after[i])-height[i];
            if(k>0)
            ans+=k;
        }
        return ans;
    }
};