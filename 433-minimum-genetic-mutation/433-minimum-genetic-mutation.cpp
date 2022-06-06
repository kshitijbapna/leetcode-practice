class Solution {
public:
    map<string,set<string>> m;
    map<string,int> vis;
    int minMutation(string start, string end, vector<string>& bank) {
        bank.push_back(start);
        set<string> s(bank.begin(),bank.end());
        for(int i=0;i<bank.size();i++){
            for(int j=i+1;j<bank.size();j++){
                int cnt=0;
                for(int k=0;k<8;k++){
                    if(bank[i][k]!=bank[j][k])cnt++;
                }
                if(cnt==1){
                    m[bank[i]].insert(bank[j]);
                    m[bank[j]].insert(bank[i]);
                }
            }
        }
        queue<string> q;
        q.push(start);
        vis[start]=0;
        while(q.size()>0){
            string x=q.front();
            q.pop();
            for(auto y : m[x]){
                if(vis[y]==0){
                    vis[y]=vis[x]+1;
                    q.push(y);
                    if(y==end)return vis[y];
                }
            }
        }
        return -1;
    }
};