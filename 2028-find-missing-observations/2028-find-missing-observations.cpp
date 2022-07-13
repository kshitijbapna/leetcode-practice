class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        // sum+sig_rolls/(n+m)=mean;
        // sum+sig_rools=mean*(n+m);
        // sum=mean*()-sig_rolls;
        int known_sum=0,unknown_sum=0;
        for(int i=0;i<rolls.size();i++){
            known_sum+=rolls[i];
        }
        unknown_sum=mean*(n+rolls.size())-known_sum;
        if(unknown_sum<n||unknown_sum>6*n)return {};
        vector<int> ans(n,unknown_sum/n);
        unknown_sum-=n*(unknown_sum/n);
        int i=0;
        while(unknown_sum--){
            ans[i++]++;
        }
        return ans;
    }
};