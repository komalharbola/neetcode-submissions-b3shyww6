class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int n=matrix.size(),m=matrix[0].size();
       int left=0,right= m*n-1;
       while(left<=right){
        int mid=(left+right)/2;
        int row=mid/m;
        int col=mid%m;
        if(matrix[row][col]==target)return true;
        if(matrix[row][col]>target)right=mid-1;
        else left=mid+1; 
       }
       return false;
    }
};
