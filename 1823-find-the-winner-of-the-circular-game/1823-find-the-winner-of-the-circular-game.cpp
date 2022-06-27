class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v(n);
        int rem=n,ci=0;
        while(rem>1){
            int tmp=k;
            while(tmp){
                if(v[ci]==0){
                    tmp--;
                }
                ci++;
                if(ci==n)ci=0;
            }
            if(ci>=1)
            v[ci-1]=-1;
            else v[n-1]=-1;
            rem--;
            // for(int i=0;i<n;i++)cout<<v[i]<<" ";
            // cout<<"\n";
        }
        for(int i=0;i<n;i++)if(v[i]==0)return i+1;
        return 0;
    }
};