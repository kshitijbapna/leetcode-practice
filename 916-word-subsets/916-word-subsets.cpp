class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> v(26);
        for(auto word : words2){
            vector<int> x(26);
            for(int i=0;i<word.size();i++){
                x[word[i]-'a']++;
            }
            for(int i=0;i<26;i++){
                v[i]=max(v[i],x[i]);
            }
        }
        vector<string> ans;
        for(auto word : words1){
            vector<int> x(26);
            for(int i=0;i<word.size();i++){
                x[word[i]-'a']++;
            }
            bool f=1;
            for(int i=0;i<26;i++){
                if(x[i]<v[i])f=0;
            }
            if(f)ans.push_back(word);
        }
        return ans;
    }
};