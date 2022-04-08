class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        vector<char> v[numRows];
        int j=0,f=0;
        for(int i=0;i<s.size();i++){
            // if(j<0||j>=numRows)break;
            // cout<<j<<" ";
            if(f==0){
                v[j].push_back(s[i]);
                j++;
                if(j==numRows){
                    f=1;
                    j-=2;
                }
            }
            else{
                v[j].push_back(s[i]);
                j--;
                if(j==-1){
                    f=0;
                    j+=2;
                }
            }
        }
        string ans;
        for(int i=0;i<numRows;i++)for(int j=0;j<v[i].size();j++)ans+=v[i][j];
        return ans;
    }
};