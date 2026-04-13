class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans=0,minCP=p[0];

        int n=p.size();
        for(int i=1;i<n;i++){
            ans=max(ans,p[i]-minCP);
           minCP=min(minCP,p[i]);
        }
        return ans;
    }
};
