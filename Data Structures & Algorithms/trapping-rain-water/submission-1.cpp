class Solution {
public:
int leftM(vector<int>& h,int i){
    int ans=0;
    for(int j=i-1;j>=0;j--){
      ans=max(ans,h[j]);
    }
    return ans;
}
int rightM(vector<int>& h,int i){
    int ans=0;
    for(int j=i+1;j<h.size();j++){
      ans=max(ans,h[j]);
    }
    return ans;
}
    int trap(vector<int>& h) {
        int n=h.size();
        int ans=0;
        for(int i=1;i<n;i++){
            int amt= min(leftM(h,i),rightM(h,i))-h[i];
            if(amt>0)
            ans += (amt);
        }
       
        
        return ans;
    }
};
