class Solution {
public:
    vector<int> g[100005];
    int lowTimes[100005],times[100005];
    bool vis[100005];
    vector<vector<int>> ans;
    int time=0;
    void dfs(int currentNode,int parentNode){
        vis[currentNode]=1;
        times[currentNode]=lowTimes[currentNode]=time++;
        for(int neighbourNode : g[currentNode]){
            if(neighbourNode==parentNode)continue;
            if(!vis[neighbourNode]){
                dfs(neighbourNode,currentNode);
                lowTimes[currentNode]=min(lowTimes[currentNode],lowTimes[neighbourNode]);
                if(times[currentNode]<lowTimes[neighbourNode]){
                    vector<int> xx{currentNode,neighbourNode};
                    ans.push_back(xx);
                }
            }
            else{
                lowTimes[currentNode]=min(lowTimes[currentNode],lowTimes[neighbourNode]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for(int i=0;i<connections.size();i++){
            g[connections[i][0]].push_back(connections[i][1]);
            g[connections[i][1]].push_back(connections[i][0]);
        }
        dfs(0,-1);
        return ans;
    }
};