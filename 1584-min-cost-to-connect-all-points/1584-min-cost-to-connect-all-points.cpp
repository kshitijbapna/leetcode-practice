class Solution {
public:
    vector<pair<int,int>> adj[1001];
    vector<int> parent;
    int find_set(int node){
        if(parent[node]==-1)return node;
        return parent[node]=find_set(parent[node]);
    }
    int union_set(int s1,int s2){
        int p1=find_set(s1);
        int p2=find_set(s2);
        if(p1==p2){
            return -1;
        }
        else{
            parent[p1]=p2;
        }
        return 1;
    }
    
    int minCostConnectPoints(vector<vector<int>>& ps) {
        //creating the adjacency list
        for(int i=0;i<ps.size();i++){
            for(int j=i+1;j<ps.size();j++){
                int dis=abs(ps[i][0]-ps[j][0])+abs(ps[i][1]-ps[j][1]);
                adj[i].push_back({dis,j});
            }
        }
        parent.resize(1001);
        for(int i=0;i<1001;i++)parent[i]=-1;
        // greedy
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int i=0;i<1001;i++){
            for(auto x : adj[i]){
                pq.push({x.first,{i,x.second}});
            }
        }
        int take=ps.size()-1,ans=0;
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            int dis=x.first;
            int n1=x.second.first,n2=x.second.second;
            if(union_set(n1,n2)!=-1){
                take--;
                ans+=dis;
            }
            if(take==0)break;
        }
        return ans;
    }
};