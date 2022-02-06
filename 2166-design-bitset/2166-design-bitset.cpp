class Bitset {
public:
    int bi[100005];
    int ai[100005];
    int curr=1;
    int siz=0,cnt=0;
    Bitset(int size) {
        siz=size;
        memset(bi,0,sizeof(bi));
        for(int i=0;i<siz;i++){
            ai[i]=1;
        }
    }
    
    void fix(int idx) {
        if(curr==1){
            if(bi[idx]==0)cnt++;
            bi[idx]=1;
            ai[idx]=(!bi[idx]);
        }
        else{
            if(ai[idx]==0)cnt++;
            ai[idx]=1;
            bi[idx]=(!ai[idx]);
        }
        
    }
    
    void unfix(int idx) {
        if(curr==1){
            if(bi[idx]==1)cnt--;
            bi[idx]=0;
            ai[idx]=(!bi[idx]);
        }
        else{
            if(ai[idx]==1)cnt--;
            ai[idx]=0;
            bi[idx]=(!ai[idx]);
        }
        
    }
    
    void flip() {
        if(curr==1)curr=2;
        else curr=1;
        cnt=siz-cnt;
    }
    
    bool all() {
        if(cnt==siz)return 1;
        return 0;
    }
    
    bool one() {
        if(cnt>=1)return 1;
        return 0;
    }
    int count() {
        return cnt;
    }
    
    string toString() {
        string s;
        if(curr==1)
        for(int i=0;i<siz;i++){
            s+=(char)('0'+bi[i]);
        }
        else 
            for(int i=0;i<siz;i++){
            s+=(char)('0'+ai[i]);
        }
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */