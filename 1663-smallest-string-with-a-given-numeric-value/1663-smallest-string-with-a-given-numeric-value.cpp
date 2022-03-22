class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        for(int i=0;i<n;i++)ans+='a';
        k-=n;
        int j=n-1;
        while(k>0){
            int x=min(k,25);
            k-=x;
            ans[j]+=x;
            j--;
        }
        return ans;
    }
};