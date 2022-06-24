class Solution {
public:
    int find_set(vector<int> &parent,int n){
        if(parent[n]==-1)return n;
        return parent[n]=find_set(parent,parent[n]);
    }
    bool unite(vector<int> &parent,vector<int> &rank,int x,int y){
        int s1=find_set(parent,x);
        int s2=find_set(parent,y);
        if(s1==s2)return 0;
        if(rank[s1]<rank[s2]){
            parent[s1]=s2;
            rank[s2]+=rank[s1];
        }
        else{
            parent[s2]=s1;
            rank[s1]+=rank[s2];
        }
        return 1;
    }
    int minCostConnectPoints(vector<vector<int>>& ps) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<ps.size();i++){
            for(int j=i+1;j<ps.size();j++){
                int dis=abs(ps[i][0]-ps[j][0])+abs(ps[i][1]-ps[j][1]);
                pq.push({dis,{i,j}});
            }
        }
        vector<int> parent(ps.size(),-1),rank(ps.size(),1);
        int ans=0,k=ps.size()-1;
        while(k>0){
            pair<int,pair<int,int>> x=pq.top();
            pq.pop();
            if(unite(parent,rank,x.second.first,x.second.second)){
                ans+=x.first;
                k--;
            }
        }
        return ans;
    }
};