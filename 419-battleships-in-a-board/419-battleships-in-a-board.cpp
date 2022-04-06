class Solution {
public:
    int countBattleships(vector<vector<char>>& b) {
        int ans=0;
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[0].size();j++){
                if(b[i][j]=='X'){
                    ans++;
                    int k=i+1;
                    while(k<b.size()&&b[k][j]=='X'){
                        b[k][j]='.';k++;
                    }
                    k=j+1;
                    while(k<b[0].size()&&b[i][k]=='X'){
                        b[i][k]='.';
                        k++;
                    }
                }
            }
        }
        return ans;
    }
};