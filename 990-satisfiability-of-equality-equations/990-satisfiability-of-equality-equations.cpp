class Solution {
public:
    vector<char> v[26];
    int a[26],x=0;
    bool vis[26];
    void dfs(int n){
        vis[n]=1;
        a[n]=x;
        for(char aa : v[n]){
            if(!vis[aa-'a'])dfs(aa-'a');
        }
    }
    bool equationsPossible(vector<string>& eq) {
        for(int i=0;i<eq.size();i++){
            if(eq[i][1]=='='){
                v[eq[i][3]-'a'].push_back(eq[i][0]);
                v[eq[i][0]-'a'].push_back(eq[i][3]);
            }
        }
        memset(a,0,sizeof(a));
        for(int i=0;i<26;i++){
            if(vis[i]==1)continue;
            x++;
            dfs(i);
        }
        // for(int i=0;i<26;i++){
            // cout<<(char)('a'+i)<<" "<<a[i]<<"\n";
        // }
        for(int i=0;i<eq.size();i++){
            if(eq[i][1]=='!'){
                if(a[eq[i][0]-'a']==a[eq[i][3]-'a'])return false;
            }
        }
        
        return true;
    }
};