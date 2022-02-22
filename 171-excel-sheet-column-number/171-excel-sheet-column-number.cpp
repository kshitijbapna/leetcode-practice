class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long int ans=0;
        int k=0;
        for(int i=columnTitle.size()-1;i>=0;i--){
            ans+=pow(26,k)*(columnTitle[i]-'A'+1);
            k++;
        }
        return ans;
    }
};