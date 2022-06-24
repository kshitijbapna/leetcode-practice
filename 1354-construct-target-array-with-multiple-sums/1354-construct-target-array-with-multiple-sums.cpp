class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long int sum=0;
        priority_queue<int> pq;
        for(auto val : target){
            pq.push(val);
            sum+=val;
        }
        while(pq.top()!=1){
            int num = pq.top();
            pq.pop();
            sum -= num;
            if (num <= sum || sum < 1) return false;
            num %= sum, sum += num, pq.push(num ? num : sum);
        }
        // if(pq.size()>0)return 0;
        return 1;
    }
};