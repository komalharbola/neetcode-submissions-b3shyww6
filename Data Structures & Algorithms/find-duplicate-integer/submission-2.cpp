class Solution {
public:
    int findDuplicate(vector<int>& nums) {
         int left = 1, right = nums.size() - 1;
         while(left < right) {
            int mid = left + (right - left) / 2;
            
            // Count how many numbers are ≤ mid
            int count = 0;
            for(int num : nums) {
                if(num <= mid) count++;
            }
            
            // If count > mid, duplicate is in [left, mid]
            if(count > mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};
