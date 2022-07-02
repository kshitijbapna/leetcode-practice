class Solution {
public:
    string find(string s,map<string,string> &parents){
        if(parents[s]==s){
            return s;
        }
        return parents[s]=find(parents[s],parents);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,string> owner;
        map<string,string> parents;
        map<string,set<string>> unions;
        
        for(auto act : accounts){
            for(int j=1;j<act.size();j++){
                parents[act[j]]=act[j];
                owner[act[j]]=act[0];
            }
        }
        for(auto act : accounts){
            string p=find(act[1],parents);
            for(int j=2;j<act.size();j++){
                parents[find(act[j],parents)]=p;
            }
        }
        for(auto act : accounts){
            for(int j=1;j<act.size();j++){
                unions[find(act[j],parents)].insert(act[j]);
            }
        }
        vector<vector<string>> res;
        for(auto p : unions){
            vector<string> emails(p.second.begin(),p.second.end());
            emails.insert(emails.begin(),owner[p.first]);
            res.push_back(emails);
        }
        return res;
    }
};