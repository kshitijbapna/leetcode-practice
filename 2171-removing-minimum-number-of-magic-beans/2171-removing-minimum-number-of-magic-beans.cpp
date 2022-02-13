class Solution {
public:
   
    long long minimumRemoval(vector<int>& b) {
        if(b.size()==1)return 0;
        long long s1=0,s2=0,n=b.size();
        map<int,int> m;
        for(int i=0;i<n;i++){
            s2+=b[i];
            m[b[i]]++;
        }
        long long ans=s2,sx=0,don=0;
        for(auto x: m){
            long long fi=x.first,se=x.second;
            don+=se;
            s2-=fi*se;
            long long zz=s1+s2-(n-don)*fi;
            ans=min(ans,zz);
            s1+=fi*se;
        }
        return ans;
    }
};