class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size())return 0;
        vector<int> x(26);
        vector<int> y(26);
        for(int i=0;i<s1.size();i++){
            x[s1[i]-'a']++;
            y[s2[i]-'a']++;
        }
        
        for(int i=0;i<=s2.size()-s1.size();i++){
            bool f=1;
            if(!i){
                for(int j=0;j<26;j++)if(x[j]!=y[j])f=0;
                if(f==1)return 1;
                continue;
            }
            y[s2[i-1]-'a']--;
            y[s2[i+s1.size()-1]-'a']++;
            for(int j=0;j<26;j++)if(x[j]!=y[j])f=0;
            if(f==1)return 1;
        }
        return 0;
    }
};