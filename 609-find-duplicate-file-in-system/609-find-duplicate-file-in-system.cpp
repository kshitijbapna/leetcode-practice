class Solution {
public:
    map<string,vector<string>> m;
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        for(auto path : paths){
            int i=0;
            string pth;
            while(path[i]!=' ')pth+=path[i++];
            i++;
            string filename,content;
            bool f=1;
            for(;i<path.size();i++){
                if(f){
                    if(path[i]=='('){
                        f=0;
                    }
                    else filename+=path[i];
                }
                else{
                    if(path[i]==')'){
                        // cout<<content<<" "<<filename<<" "<<path<<"\n";
                        i++;
                        f=1;
                        m[content].push_back(pth+"/"+filename);
                        content="";
                        filename="";
                    }
                    else{
                        content+=path[i];
                    }
                }
                
            }
        }
        vector<vector<string>> ans;
        for(auto x : m){
            if(x.second.size()>1)
            ans.push_back(x.second);
        }
        return ans;
    }
};