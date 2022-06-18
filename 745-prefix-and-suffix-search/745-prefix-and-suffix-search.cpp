class WordFilter {
public:
    unordered_map<string,int> m;
    WordFilter(vector<string>& words) {
        int n=words.size(),i=-1;
        for(auto word : words){
            int sz=word.size();
            i++;
            string pref,suff;
            for(int j=0;j<sz;j++){
                pref+=word[j];
                suff=pref+".";
                for(int k=sz-1;k>=0;k--){
                    suff+=word[k];
                    m[suff]=i+1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string s=prefix+"."+(string){suffix.rbegin(), suffix.rend()};
        return m[s]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */