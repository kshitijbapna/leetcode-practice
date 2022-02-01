class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_before=prices[0], max_profit=0;
        
        for(int i=1;i<prices.size();i++){
            if(prices[i]>min_before){
                max_profit=max(max_profit,prices[i]-min_before);
            }
            min_before=min(min_before,prices[i]);
        }
        
        return max_profit;
    }
};