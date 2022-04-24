class UndergroundSystem {
public:
    map<int,vector<string>> m;
    map<pair<string,string>,vector<int>> pa;
    UndergroundSystem() {
        
    }
    void checkIn(int id, string stationName, int t) {
        m[id].push_back(stationName);
        m[id].push_back(to_string(t));
    }
    
    void checkOut(int id, string stationName, int t) {
        string st=m[id][0];
        int ti=stoi(m[id][1]);
        m[id].clear();
        pa[{st,stationName}].push_back(t-ti);
    }
    
    double getAverageTime(string startStation, string endStation) {
        int sum=0;
        // cout<<startStation<<" "<<endStation<<" ";
        for(int i=0;i<pa[{startStation,endStation}].size();i++){
            // cout<<pa[{startStation,endStation}][i]<<" ";
            sum+=pa[{startStation,endStation}][i];
        }
        cout<<"\n";
        return 1.0*sum/pa[{startStation,endStation}].size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */