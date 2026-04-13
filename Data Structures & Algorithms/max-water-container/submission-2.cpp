class Solution {
public:
    int maxArea(vector<int>& h) {
       int n= h.size();
       int left=0,right=n-1;
       int Ar=0;
        while(left<right){
           int amt=min(h[left],h[right])*(right-left);
          
           Ar= max(Ar,amt);
            if(h[left]<h[right]) left++;
           else right--;
        }

        return Ar;
           }
};
