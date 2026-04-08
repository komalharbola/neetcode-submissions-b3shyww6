class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         int prod=1;
         int zero=0,zeroC=0;
         vector<int> ans(nums.size(),0);
         for(int i=0;i<nums.size();i++){
            if(nums[i]==0) {zero=i; zeroC++;}
            else prod *= nums[i];
         }
       if(zeroC >1) {
        return ans;
       }
       else if(zeroC==1){
        ans[zero]=prod;
        return ans;
       }
       else{
        for(int i=0;i<nums.size();i++){
            ans[i]= prod/nums[i];
        }
       }
       return ans;

    }
};
