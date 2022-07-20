class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> v[26];
        int res=0;
        for(int i=0;i<s.size();i++)v[s[i]-'a'].push_back(i);
        for(auto word : words){
            int in=-1,f=1;
            for(int i=0;i<word.size();i++){
                auto it=upper_bound(v[word[i]-'a'].begin(),v[word[i]-'a'].end(),in);
                if(it==v[word[i]-'a'].end()){
                    f=0;
                    break;
                }
                in=*it;
            }
            if(f){
                // cout<<word<<"\n";
                res++;
            }
        }
        return res;
    }
};