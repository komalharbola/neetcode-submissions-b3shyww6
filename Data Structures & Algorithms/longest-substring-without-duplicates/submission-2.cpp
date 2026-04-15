class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        if(s.size()<2) return s.size();
        vector<int> vis(256,0);
        int l=0,r=0;
        while(r<s.size()){
            while(vis[s[r]] != 0){
               vis[s[l]]--;
                l++;
            }
           
               vis[s[r]]++;
                r++;
            
            ans=max(ans,r-l);
        }
        return ans;
    }
};
