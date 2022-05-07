class MagicDictionary {
public:
    vector<string> v;
    MagicDictionary() {
        
    }
    void buildDict(vector<string> dictionary) {
        v=dictionary;
    }
    
    bool search(string s) {
        for(int i=0;i<v.size();i++){
            if(v[i].size()==s.size()){
                int k=0;
                for(int j=0;j<s.size();j++){
                    if(v[i][j]!=s[j])k++;
                }
                if(k==1)return 1;
            }
        }
        return 0;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */