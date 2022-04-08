
class Solution {
public:
   
    int wordCount(vector<string>& sta, vector<string>& tar) {
        int ans=0,i,j,k;
        set<int> s;
        for(auto ss :sta){
            int hash=0;
            for(auto ch : ss)hash+=pow(2,ch-'a');
            s.insert(hash);
        }
        for(auto st : tar){
            for(k=0;k<st.size();k++){
                int hash=0;
                for(i=0;i<st.size();i++){
                    if(i==k)continue;
                    hash+=pow(2,st[i]-'a');
                }
                if(s.count(hash)>0){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};