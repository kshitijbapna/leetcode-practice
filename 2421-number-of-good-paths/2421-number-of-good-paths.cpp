class DS{
    vector<int> parent,rank;
    public:
    DS(int sz){
        parent.resize(sz);
        rank.resize(sz);
        for(int i=0;i<sz;i++)
            parent[i]=i;
    }
    int find(int x){
        if(parent[x]!=x)
            parent[x]=find(parent[x]);
        return parent[x];
    }
    void join(int x,int y){
        int pX=find(x),pY=find(y);
        if(pX==pY)return;
        if(rank[pX]>rank[pY])
            parent[pY]=pX;
        else if(rank[pX]<rank[pY])
            parent[pX]=pY;
        else{
            parent[pY]=pX;
            rank[pX]++;
        }
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        vector<int> adj[30005];
        map<int,vector<int>> val2nodes;
        for(int i=0;i<n;i++){
            val2nodes[vals[i]].push_back(i);
        }
        for(auto x : edges){
            int nA=x[0],nB=x[1];
            if(vals[nA]>=vals[nB])
                adj[nA].push_back(nB);
            if(vals[nA]<=vals[nB])
                adj[nB].push_back(nA);
        }
        DS *ds=new DS(n);
        int res=0;
        for(auto x : val2nodes){
            int val=x.first;
            for(auto &node : x.second){
                for(auto neighbor : adj[node]){
                    ds->join(node,neighbor);
                }
            }
            unordered_map<int,int> group2size;
            for(auto &node:x.second){
                group2size[ds->find(node)]++;
            }
            res+=x.second.size();
            for(auto& [groupID,size] : group2size){
                res+=size*(size-1)/2;
            }
        }
        return res;
    }
};