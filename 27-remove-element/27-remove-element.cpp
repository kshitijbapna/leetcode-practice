class Solution {
public:
    int removeElement(vector<int>& v, int val) {
        int i=0;
        while(i<v.size()){
            if(v[i]==val){
                v.erase(v.begin()+i);
            }
            else i++;
        }return v.size();
    }
};