class Solution {
public:
    vector<int> v[100005];
    bool vis[100005];
    string indiceString;
    vector<int> indices;
    void dfs(string &s,int n){
        vis[n]=1;
        indices.push_back(n);
        indiceString+=s[n];
        for(auto &i : v[n]){
            if(!vis[i])dfs(s,i);
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& p) {
    
        for(int i=0;i<p.size();i++){
            v[p[i][0]].push_back(p[i][1]);
            v[p[i][1]].push_back(p[i][0]);
        }
        for(int i=0;i<s.size();i++){
            if(!vis[i]){
                indiceString="";
                indices.clear();
                dfs(s,i);
                sort(indiceString.begin(),indiceString.end());
                sort(indices.begin(),indices.end());
                for(int i=0;i<indices.size();i++){
                    s[indices[i]]=indiceString[i];
                }
            }
        }
        return s;
    }
};