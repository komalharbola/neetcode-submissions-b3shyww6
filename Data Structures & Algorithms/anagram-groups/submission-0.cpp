class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,int> mp;
        for(int i=0;i<strs.size();i++){
           string str= strs[i];
           sort(str.begin(),str.end());
           if(mp.find(str) == mp.end()){
           
            mp[str]=ans.size();
            ans.push_back({});
            
           }
        
           
             ans[mp[str]].push_back(strs[i]);
           
        }
        return ans;
    }
};
