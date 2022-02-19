class Solution {
public:
    // static bool comp(vector<int> a,vector<int> b){
    //     return a[0]>b[0];
    // }
    // int closest(vector<int> v,int x){
    //     int in=lower_bound(v.begin(),v.end(),x)-v.begin();
    //     if(in==v.size())return v[v.size()-1];
    //     if(in==0)return v[0];
    //     if(abs(v[in]-x)<abs(v[in-1]-x))return v[in];
    //     return v[in-1];
    // }
    int minimumDeviation(vector<int>& nums) {
        int n=nums.size();
        // vector<int> poss[n];
        // for(int i=0;i<nums.size();i++){
        //     poss[i].push_back(nums[i]);
        //     if(nums[i]%2){
        //         poss[i].push_back(nums[i]*2);
        //         continue;
        //     }
        //     while(nums[i]%2==0){
        //         nums[i]/=2;
        //         poss[i].push_back(nums[i]);
        //     }
        //     sort(poss[i].begin(),poss[i].end());
        // }
        // sort(poss,poss+n,comp);
        // int ans=INT_MAX,k=0;
        // for(int xx=0;xx<min(n,10);xx++){
        //     for(auto x : poss[xx]){
        //         k=0;
        //         for(int i=0;i<n;i++)k=max(k,abs(closest(poss[i],x)-x));
        //         ans=min(ans,k);
        //         cout<<x<<" "<<ans<<" "<<k<<"\n";
        //     }
        // }
        // // cout<<"\n";
        // // for(int i=0;i<n;i++){
        // //     for(int j=0;j<poss[i].size();j++)cout<<poss[i][j]<<" ";
        // //     cout<<"\n";
        // // }
        // // cout<<"\n";
        // return ans;
        
        int mx=INT_MIN,mi=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]%2)nums[i]*=2;
            mx=max(mx,nums[i]);
            mi=min(mi,nums[i]);
        }
        int min_dev=mx-mi;
        priority_queue<int> pq;
        for(int i=0;i<n;i++)pq.push(nums[i]);
        while(pq.top()%2==0){
            int top=pq.top();
            pq.pop();
            min_dev=min(min_dev,top-mi);
            top/=2;
            mi=min(mi,top);
            pq.push(top);
        }
        min_dev=min(min_dev,pq.top()-mi);
        return min_dev;
    }
};