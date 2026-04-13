class Solution {
public:
    int trap(vector<int>& h) {
       int res=0;
       int n=h.size();
       int maxL=h[0],maxR=h[n-1];
       int l=1,r=n-2;
       while(l<=r){
        if(maxL<maxR){
            if(maxL-h[l]>0)
            res +=(maxL-h[l]);
            maxL=max(maxL,h[l]);
            l++;
        }
        else{
            if(maxR-h[r]>0)
            res +=(maxR-h[r]);
            maxR=max(maxR,h[r]);
            r--;  
        }
       } 
       return res;
    }
};
