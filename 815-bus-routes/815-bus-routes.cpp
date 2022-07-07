class Solution {
public:
    int help(vector<vector<int>> &routes,unordered_map<int,vector<int>> &bus_stops,int src,int des){
        if(src==des)return 0;
        unordered_map<int,bool> vis_stops;
        for(auto it : bus_stops){
            vis_stops[it.first]=0;
        }
        vector<bool> vis_bus(routes.size(),0);
        queue<pair<int,int>> q;
        q.push({src,0});
        vis_stops[src]=1;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            int curr_stop=front.first,cnt=front.second;
            if(curr_stop==des)return cnt;
            vector<int> bus_options=bus_stops[curr_stop];
            for(int i=0;i<bus_options.size();i++){
                int curr_bus=bus_options[i];
                if(vis_bus[curr_bus])continue;
                else{
                    vector<int> next_stops=routes[curr_bus];
                    for(int j=0;j<next_stops.size();j++){
                        int next_stop=next_stops[j];
                        if(vis_stops[next_stop])continue;
                        else{
                            q.push({next_stop,cnt+1});
                            vis_stops[next_stop]=1;
                        }
                    }
                    vis_bus[curr_bus]=1;
                }
            }
        }
        return -1;
    }
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        int n=routes.size();
        if(S==T||n==0)return 0;
        unordered_map<int,vector<int>> bus_stops;
        for(int i=0;i<n;i++){
            for(int j=0;j<routes[i].size();j++){
                int curr_stop=routes[i][j];
                int curr_bus=i;
                bus_stops[curr_stop].push_back(curr_bus);
            }
        }
        return help(routes,bus_stops,S,T);
    }
};