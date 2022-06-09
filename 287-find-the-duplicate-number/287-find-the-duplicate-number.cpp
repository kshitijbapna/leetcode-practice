class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int i=0,rep=-1,n=arr.size();
        while(i<n){
            if(arr[i]==i+1)i++;
            else{
                int tmp=arr[arr[i]-1];
                if(tmp==arr[i]){
                    rep=arr[i];
                    break;
                }
                arr[arr[i]-1]=arr[i];
                arr[i]=tmp;
            }
        }
        return rep;
    }
};