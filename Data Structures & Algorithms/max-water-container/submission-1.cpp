class Solution {
public:

    int maxArea(vector<int>& h) {
        int maxA=0;
        for(int i=0;i<h.size();i++){
          for(int j=i+1;j<h.size();j++){
            int amt=min(h[i],h[j])*(j-i);
            maxA=max(amt,maxA);
          }
        }
     return maxA;   
    }
};
