class Solution {
public:
    int numSub(string s) {
        int i=0,j=0,n=s.size();
        long long ans=0;
        while(i<n){
            if(s[i]=='0'){
                i++;
                continue;
            }
            int j=i+1;
            while(j<n&&s[j]=='1')j++;
            ans+=(long long)(j-i)*(j-i+1)/2;
            ans%=(int)(1e9+7);
            i=j;
        }
        return ans;
    }
};