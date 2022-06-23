class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev{1};
        while(rowIndex--){
            vector<int> curr;
            curr.push_back(1);
            for(int i=1;i<prev.size();i++){
                curr.push_back(prev[i-1]+prev[i]);
            }
            curr.push_back(1);
            prev=curr;
        }
        return prev;
    }
};