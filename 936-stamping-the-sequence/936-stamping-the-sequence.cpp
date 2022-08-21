class Solution {
public:
    bool match(string &a,string &b){
        if(a.size()!=b.size())return 0;
        for(int i=0;i<a.size();i++)if(a[i]!=b[i]&&a[i]!='?'&&b[i]!='?')return 0;
        return 1;
    }
    bool allw(string &s){
        for(int i=0;i<s.size();i++){
            if(s[i]!='?')return 0;
        }
        return 1;
    }
    vector<int> movesToStamp(string stamp, string target) {
        int n=target.size(),m=stamp.size();
        string s;
        vector<int> ans;
        bool f=1;
        while(f){
            f=0;
            for(int i=0;i<n-m+1;i++){
                s=target.substr(i,m);
                if(allw(s))continue;
                if(match(stamp,s)){
                    f=1;
                    ans.push_back(i);
                    for(int j=0;j<m;j++)target[i+j]='?';
                }
            }
        }
        if(!allw(target))ans.clear();
        if(ans.size()>10*n)ans.clear();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};