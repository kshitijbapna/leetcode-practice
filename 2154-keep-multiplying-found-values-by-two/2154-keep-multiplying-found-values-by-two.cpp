class Solution {
public:
    int findFinalValue(vector<int>& n, int original) {
        int j=60;
        int mx=*max_element(n.begin(),n.end());
        while(j--){
            for(int i=0;i<n.size();i++){
                if(n[i]==original){
                    original*=2;
                }
            }
            if(original>=2*mx)break;
        }
        return original;
    }
};