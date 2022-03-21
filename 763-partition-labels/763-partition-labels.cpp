class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                set<char> sx;
                for(int k=i;k<=j;k++)sx.insert(s[k]);
                bool f=1;
                for(int k=j+1;k<n;k++){
                    if(sx.count(s[k])==1)f=0;
                }
                if(f){
                    ans.push_back(j-i+1);
                    i=j;
                    break;
                }
            }
        }
        return ans;
    }
};