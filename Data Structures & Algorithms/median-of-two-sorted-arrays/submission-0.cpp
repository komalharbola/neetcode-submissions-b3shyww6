class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int m=nums1.size();
        int n=nums2.size();
        vector<int> temp(nums1.begin(),nums1.end());
        for(auto n:nums2){
            temp.push_back(n);
        }
        sort(temp.begin(),temp.end());
        double ans;
       if((n+m)%2 == 0){
return (temp[(n+m)/2-1]+temp[(n+m)/2])/2.0;
       }else{
        return temp[(n+m)/2];
       }
         
    }
};
