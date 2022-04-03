class Encrypter {
public:
    set<char> s[26];
    map<char,string> m;
    map<string,char> m1;
    vector<string> dic;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        dic=dictionary;
        for(int i=0;i<keys.size();i++){
            s[keys[i]-'a'].insert(keys[i]);
            m[keys[i]]=values[i];
            m1[values[i]]=keys[i];
            for(int j=i+1;j<keys.size();j++){
                if(values[j]==values[i]){
                    s[keys[i]-'a'].insert(keys[j]);
                    s[keys[j]-'a'].insert(keys[i]);
                }
            }
        }
    }
    
    string encrypt(string word1) {
        string ans;
        for(int i=0;i<word1.size();i++)ans+=m[word1[i]];
        return ans;
    }
    
    int decrypt(string word2) {
        int ans=0;
        for(int i=0;i<dic.size();i++){
            if(dic[i].size()*2==word2.size()){
                int j;
                for(j=0;j<dic[i].size();j++){
                    string x;
                    x+=word2[2*j];
                    x+=word2[2*j+1];
                    char b=m1[x];
                    if(b==0)break;

                    if(s[b-'a'].count(dic[i][j])==1)continue;
                    break;
                }
                if(j==dic[i].size())ans++;
            }
        }
        return ans;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */