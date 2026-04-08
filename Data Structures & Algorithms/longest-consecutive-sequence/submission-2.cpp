class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        int ans=1,maxi=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                ans++;
            }
            else if(nums[i]==nums[i-1]){
                ans =ans;
            }
            else{
                ans=1;
            }
            maxi=max(ans,maxi);
        }
        return maxi;
    }
};
