class Solution {
public:
    string repeatLimitedString(string s, int re) {
        vector<int> v(26);
        int n=s.size();
        for(int i=0;i<s.size();i++)v[s[i]-'a']++;
        reverse(v.begin(),v.end());
        // for(int i=0;i<26;i++)cout<<v[i]<<" ";
        // cout<<"\n";
        int i=0,j;
        string ans;
        while(1){
            while(i<26&&v[i]==0)i++;
            j=i+1;
            while(j<26&&v[j]==0)j++;
            if(i>=26)break;
            int x=re;
            if(v[i]>re){
                v[i]-=re;
                while(x--)ans+='a'+25-i;
                if(j>=26)break;
                ans+='a'+25-j;
                v[j]--;
            }
            else{
                while(v[i]>=1){
                    ans+='a'+25-i;
                    v[i]--;
                }
            }
        }
        return ans;
    }
};