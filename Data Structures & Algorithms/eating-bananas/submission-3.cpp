class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
                int maxi=*max_element(piles.begin(),piles.end());
      int left=1,right=maxi;
      int ans=INT_MAX;
      while(left<=right){
        int mid=left+(right-left)/2;
       long long reqTime=0;
          for(int i=0;i<piles.size();i++){
             reqTime += (piles[i]+mid-1)/mid;
          }
          
           if(reqTime<=h) ans=min(ans,mid);
           if(reqTime > h) left=mid+1;
           else right=mid-1;
         
      }
      return ans;
    }
};
