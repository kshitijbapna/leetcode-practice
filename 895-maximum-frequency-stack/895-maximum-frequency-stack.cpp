class FreqStack {
public:
    int maxf=0;
    unordered_map<int,int> fm;
    unordered_map<int,stack<int>> fstack;
    FreqStack() {
        maxf=0;
    }
    void push(int x) {
        ++fm[x];
        maxf=max(maxf,fm[x]);
        fstack[fm[x]].push(x);
    }
    int pop() {
        int curr_top=fstack[maxf].top();
        fstack[maxf].pop();
        --fm[curr_top];
        if(fstack[maxf].empty()){
            fstack.erase(maxf);
            --maxf;
        }
        return curr_top;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */