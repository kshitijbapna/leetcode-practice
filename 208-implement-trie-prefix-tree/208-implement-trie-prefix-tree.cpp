class TrieNode
{
public:
    TrieNode *next[26];
    bool is_word;
    
    // Initialize your data structure here.
    TrieNode(bool b = false)
    {
        memset(next, 0, sizeof(next));
        is_word = b;
    }
};
class Trie {
public:
    TrieNode *root;
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* p = root;
        for(int i=0;i<word.size();i++){
            if(p->next[word[i]-'a']==NULL){
                p->next[word[i]-'a']=new TrieNode();
            }
            p=p->next[word[i]-'a'];
        }
        p->is_word=1;
    }
    
    bool search(string word) {
        TrieNode* p=root;
        for(int i=0;i<word.size()&&p;i++){
            p=p->next[word[i]-'a'];
        }
        if(p!=NULL&&p->is_word==1)return 1;
        return 0;
    }
    
    bool startsWith(string word) {
       TrieNode* p=root;
        for(int i=0;i<word.size()&&p;i++){
            p=p->next[word[i]-'a'];
        }
        if(p!=NULL)return 1;
        return 0;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */