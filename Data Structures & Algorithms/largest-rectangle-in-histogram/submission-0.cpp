class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res=0;
       for(int i=0;i<heights.size();i++){
          int curr=heights[i];
          for(int j=i-1;j>=0 && heights[j]>=heights[i];j--)curr +=heights[i];
          for(int j=i+1;j<heights.size() && heights[j]>=heights[i];j++)curr +=heights[i];
          res=max(res,curr);
       } 
       return res;
    }
};
