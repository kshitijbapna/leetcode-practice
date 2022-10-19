class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> ava(26);
        for(auto l : letters)ava[l-'a']++;
        int n=words.size(),mx=1<<n,res=0;
        for(int i=0;i<mx;i++){
            vector<int> cnt(26);
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    for(auto x : words[j])
                        cnt[x-'a']++;
                }
            }
            bool f=1;
            int curr=0;
            for(int j=0;j<26;j++){
                if(ava[j]<cnt[j])f=0;
                curr+=cnt[j]*score[j];
            }
            if(f)res=max(res,curr);
        }
        return res;
    }
};