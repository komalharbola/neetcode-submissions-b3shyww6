class Solution {
    private:
     void recur(vector<int>& nums,vector<vector<int>>& ans,int i,vector<int>&temp){
       if(i== nums.size()){
         ans.push_back(temp);
         return;
       }
        temp.push_back(nums[i]);
       
    recur(nums,ans,i+1,temp);
    
        temp.pop_back();
        recur(nums,ans,i+1,temp);
       
            
     }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        recur(nums,ans,0,temp);
        return ans;
    }
};
