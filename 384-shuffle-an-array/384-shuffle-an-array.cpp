class Solution {
public:
    vector<int> og;
    vector<int> curr;
    int n;
    Solution(vector<int>& nums) {
        og=nums;
        curr=nums;
        n=nums.size();
    }
    
    vector<int> reset() {
        curr=og;
        return curr;
    }
    
    vector<int> shuffle() {
        int i=0;
        set<int> s;
        while(s.size()<n){
            int k=rand()%n;
            if(s.find(k)==s.end()){
                curr[i]=og[k];
                i++;
                s.insert(k);
            }
        }
        return curr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */