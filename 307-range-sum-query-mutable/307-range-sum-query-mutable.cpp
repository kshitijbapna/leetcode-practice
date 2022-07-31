class NumArray {
public:
    vector<int> st;
    vector<int> arr;
    int construct(int ss,int se,int si){
        if(ss==se)
            return st[si]=arr[ss];
        int mid=(ss+se)/2;
        return st[si]=construct(ss,mid,si*2+1)+construct(mid+1,se,si*2+2);
    }
    NumArray(vector<int>& nums) {
        arr=nums;
        int x=(int)(ceil(log2(nums.size())));
        int n=2*pow(2,x)-1;
        st.resize(n);
        construct(0,nums.size()-1,0);
    }
    void update(int ss,int se,int i,int diff,int si){
        if(i<ss||i>se)return;
        st[si]=st[si]+diff;
        if(se!=ss){
            int mid=(se+ss)/2;
            update(ss,mid,i,diff,2*si+1);
            update(mid+1,se,i,diff,2*si+2);
        }
    }
    void update(int index, int val) {
        int diff=val-arr[index];
        arr[index]=val;
        update(0,arr.size()-1,index,diff,0);
    }
    int sumRange(int ss,int se,int qs,int qe,int si){
        if(qs<=ss&&qe>=se)return st[si];
        if(se<qs||ss>qe)return 0;
        int mid=(ss+se)/2;
        return sumRange(ss,mid,qs,qe,2*si+1)+sumRange(mid+1,se,qs,qe,2*si+2);
    }
    int sumRange(int left, int right) {
        return sumRange(0,arr.size()-1,left,right,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */