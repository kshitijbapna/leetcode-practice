class Solution {
public:
    bool isOk(vector<int> &bD,long day,long m,long k){
        int done=0,i=0,n=bD.size(),gr=0,sm=0,j=0;
        while(i<n){
            while(j<n&&gr+sm<k){
                if(bD[j]<=day)gr++;
                else sm++;
                j++;
            }
            if(gr==k){
                done++;
                i=j;
                gr=0;
                sm=0;
            }
            else{
                if(bD[i]<=day)gr--;
                else sm--;
                if(j<n&&bD[j]<=day)gr++;
                else sm++;
                i++;
                j++;
            }
        }
        return done>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        long l=0,r=*max_element(bloomDay.begin(),bloomDay.end()),y=r;
        while(l<=r){
            long mid=(l+r)/2;
            if(isOk(bloomDay,mid,m,k)){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        if(l==y+1)return -1;
        return l;
    }
};