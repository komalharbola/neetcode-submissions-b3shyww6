class Solution {
public:
void recur(vector<int>& arr, int target,int i,vector<vector<int>>& ans,vector<int>& temp){

if(target <0 || i >= arr.size()) return;
if(target == 0){
    ans.push_back(temp);
    return;
}
temp.push_back(arr[i]);
recur(arr,target-arr[i],i,ans,temp);
temp.pop_back();
recur(arr,target,i+1,ans,temp);
}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        int i=0;
        recur(nums,target,i,ans,temp);
        return ans;
    }
};
