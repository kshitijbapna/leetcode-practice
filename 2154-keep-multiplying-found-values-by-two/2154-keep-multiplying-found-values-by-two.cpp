class Solution {
public:
    int findFinalValue(vector<int>& n, int original) {
        int j=100;
        while(j--){
            for(int i=0;i<n.size();i++){
                if(n[i]==original){
                    original*=2;
                }
            }
        }
        return original;
    }
};