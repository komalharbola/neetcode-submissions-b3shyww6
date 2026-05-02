class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0,right=k-1;
        vector<int> ans;
        while(right<n){
            int maxi=nums[left];
            for(int i=left+1;i<=right;i++){
                maxi=max(maxi,nums[i]);
            }
            ans.push_back(maxi);
            left++;right++;
        }
        return ans;
    }
};
