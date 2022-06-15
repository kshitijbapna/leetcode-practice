class Solution {
public:
    int longestStrChain(vector<string>& words) {
        map<int,vector<pair<string,int>>> m;
        for(auto word : words){
            m[word.size()].push_back({word,1});
        }
        int ans=1;
        for(int i=1;i<16;i++){
            for(auto &p1 : m[i]){
                for(auto &p2 : m[i+1]){
                    string a=p1.first,b=p2.first;
                    bool f=0;
                    int ii=0,j=0,n=i,m=i+1;
                    while(ii<n&&j<m){
                        if(f==0&&a[ii]!=b[j]){
                            j++;
                            f=1;
                        }
                        else if(a[ii]==b[j]){
                            ii++;
                            j++;
                        }
                        else break;
                    }
                    if(f==0)j++;
                    if(ii==n&&j==m){
                        p2.second=max(p2.second,p1.second+1);
                        ans=max(ans,p2.second);
                    }
                }
            }
        }
        return ans;
    }
};