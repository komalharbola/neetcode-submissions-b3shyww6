class Solution {
public:
 struct compare{
  bool operator()(const vector<int>& a,const vector<int>& b){
    long long x= (long long)a[0]*a[0]+(long long)a[1]*a[1];
    long long y= (long long)b[0]*b[0]+(long long)b[1]*b[1];
    return x<y;
  }
 };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,compare > pq;
        vector<vector<int>> ans;
        for(auto p : points){
            pq.push(p);
            if(pq.size() > k) pq.pop();
        }
        for(int i=0 ;i<k;i++){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
