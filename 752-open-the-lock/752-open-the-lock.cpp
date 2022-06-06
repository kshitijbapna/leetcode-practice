class Solution {
public:
    int vis[10000];
    void bfs(set<string>& s){
        queue<string> q;        
        q.push("0000");
        vis[0]=0;
        while(q.size()>0){
            string x=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                if(x[i]=='0'){
                    string y=x;
                    y[i]='1';
                    if(vis[stoi(y)]==-1&&s.find(y)==s.end()){
                        q.push(y);
                        vis[stoi(y)]=vis[stoi(x)]+1;
                    }
                    y[i]='9';
                    if(vis[stoi(y)]==-1&&s.find(y)==s.end()){
                        q.push(y);
                        vis[stoi(y)]=vis[stoi(x)]+1;
                    }
                }
                else if(x[i]=='9'){
                    string y=x;
                    y[i]='0';
                    if(vis[stoi(y)]==-1&&s.find(y)==s.end()){
                        q.push(y);
                        vis[stoi(y)]=vis[stoi(x)]+1;
                    }
                    y[i]='8';
                    if(vis[stoi(y)]==-1&&s.find(y)==s.end()){
                        q.push(y);
                        vis[stoi(y)]=vis[stoi(x)]+1;
                    }
                }
                else{
                    string y=x;
                    y[i]++;
                    if(vis[stoi(y)]==-1&&s.find(y)==s.end()){
                        q.push(y);
                        vis[stoi(y)]=vis[stoi(x)]+1;
                    }
                    y[i]-=2;
                    if(vis[stoi(y)]==-1&&s.find(y)==s.end()){
                        q.push(y);
                        vis[stoi(y)]=vis[stoi(x)]+1;
                    } 
                }
            }
        }
    }
    int openLock(vector<string>& d, string t) {
        set<string> s(d.begin(),d.end());
        if(s.find("0000")!=s.end())return -1;
        memset(vis,-1,sizeof(vis));
        bfs(s);
        return vis[stoi(t)];
    }
};