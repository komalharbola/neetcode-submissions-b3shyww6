class Solution {
public:
  struct compare{
    bool operator()(int a,int b){
        return a>b;
    }
  };
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>,compare> pq;
        for(int n : nums){
            pq.push(n);
            if(pq.size()>k)pq.pop();
        }
        return pq.top();
    }
};
