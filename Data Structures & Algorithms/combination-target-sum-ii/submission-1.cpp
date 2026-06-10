class Solution {
   private:
    void recur(vector<int>& arr, int target, int i, vector<vector<int>>& ans, vector<int>& temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if(target<0) return;
       for(int j=i;j<arr.size();j++){
        if(j>i && arr[j]==arr[j-1]) continue;
        if(arr[j]>target) break;
        temp.push_back(arr[j]);
       recur(arr,target-arr[j],j+1,ans,temp);
       temp.pop_back();

       }
    }

   public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        vector<int> temp;
        recur(arr, target, 0, ans, temp);
        return ans;
    }
};
