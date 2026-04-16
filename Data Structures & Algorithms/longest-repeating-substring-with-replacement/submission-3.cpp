class Solution {
public:
    int characterReplacement(string s, int k) {
      int maxFreq=0,res=0,l=0;
      unordered_map<char,int> mp;
      for(int r=0;r<s.length();r++){
mp[s[r]]++;
maxFreq=max(maxFreq,mp[s[r]]);
if(r-l+1-maxFreq>k) mp[s[l]]--,l++;
res =max(res,r-l+1);
      }  
      return res;
    }
};
