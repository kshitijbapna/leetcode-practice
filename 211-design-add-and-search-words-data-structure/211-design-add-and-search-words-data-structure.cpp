class WordDictionary {
public:
    vector<string> w[505];
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        w[word.size()].push_back(word);
    }
    
    bool search(string word) {
        int n=word.size();
        for(int i=0;i<w[n].size();i++){
                int j=0;
                for(j=0;j<word.size();j++){
                    if(word[j]=='.')continue;
                    if(w[n][i][j]!=word[j])break;
                }
                if(j==word.size())return 1;
        }
        return 0;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */