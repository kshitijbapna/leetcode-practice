class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area=0;
        heights.push_back(0);
        vector<int> ind;
        for(int i=0;i<heights.size();i++){
            while(ind.size()>0&&heights[ind.back()]>=heights[i]){
                int h=heights[ind.back()];
                ind.pop_back();
                int sidx;
                if(ind.size()>0)sidx=ind.back();
                else sidx=-1;
                if(h*(i-sidx-1)>area)area=h*(i-sidx-1);
            }
            ind.push_back(i);
        }
    return area;
    }
};