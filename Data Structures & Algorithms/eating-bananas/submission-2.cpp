class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
      

 int maxi=*max_element(piles.begin(),piles.end());
 
      for(int speed=1;speed<=maxi;speed++){
        
       long long reqTime=0;
          for(int i=0;i<piles.size();i++){
             reqTime += (piles[i]+speed-1)/speed;
          }
          if(reqTime<=h){
          return speed;
          }
      }
      return maxi;
    }
};
