class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
        vector<int> c0(n),c1(n);
        if(nums[0]==0)c0[0]++;
        for(int i=1;i<n;i++){
            if(nums[i]==0)c0[i]=c0[i-1]+1;
            else c0[i]=c0[i-1];
        }
        if(nums[n-1]==1)c1[n-1]++;
        for(int i=n-2;i>=0;i--){
            if(nums[i]==1)c1[i]=c1[i+1]+1;
            else c1[i]=c1[i+1];
        }
        int ans=0;
        set<int> s;
        vector<int> an;
        for(int i=0;i<n-1;i++){
            ans=max(ans,c0[i]+c1[i+1]);
        }
        ans=max(ans,c0[n-1]);
        ans=max(ans,c1[0]);
        int kk=ans;
         for(int i=0;i<n-1;i++){
            ans=c0[i]+c1[i+1];
             if(ans==kk)s.insert(i+1);
        }
        if(c1[0]==kk)s.insert(0);
        if(c0[n-1]==kk)s.insert(n);
    
        for(auto x: s)an.push_back(x);
        // for(int i=0;i<n;i++){
        //     ans=max(ans,c1[])
        // }
        return an;
    }
};