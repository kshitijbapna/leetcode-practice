class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        if(num<=10)return num;
        int ans=num;
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                string t=s;
                swap(t[i],t[j]);
                ans=max(ans,stoi(t));
            }
        }
        return ans;
    }
};