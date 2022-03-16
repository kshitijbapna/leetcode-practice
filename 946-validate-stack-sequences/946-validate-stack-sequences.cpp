class Solution {
public:
    bool validateStackSequences(vector<int>& pu, vector<int>& po) {
        stack<int> s;
        int j=0;
        for(int i=0;i<pu.size();i++){
            s.push(pu[i]);
            if(pu[i]==po[j]){
                
                while(!s.empty()&&po[j]==s.top()){
                    s.pop();
                    j++;
                }   
            }
        }
        if(j<po.size()){
            while(!s.empty()&&po[j]==s.top()){
                s.pop();
                j++;
            }
        }
        // cout<<s.size();
        return s.empty();
    }
    // 1 2 3 4
};