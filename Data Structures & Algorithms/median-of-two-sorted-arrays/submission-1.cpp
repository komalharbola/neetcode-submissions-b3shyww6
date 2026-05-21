class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int m=nums1.size();
        int n=nums2.size();
        int m1=-1,m2=-1;
        int i=0,j=0;
        for(int count=0;count<=(m+n)/2;count++){
            m2=m1;
            if(i!=m && j!=n){
                m1=(nums1[i]>nums2[j])?nums2[j++]:nums1[i++];
            }
            else if(i<m){
                m1=nums1[i++];
            }
            else {
                m1=nums2[j++];
            }
        }
      
       if((n+m)%2==0){
        return (m1+m2)/2.0;
       }
       else{
        return m1;
       }  
    }
};
