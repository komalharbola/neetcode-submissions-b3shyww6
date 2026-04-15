class Solution {
public:
int getMax(string s,int l,int r){
    int f=0;
    unordered_map<char,int> mp;
    for(int i=l;i<=r;i++){
      mp[s[i]]++;
    }
    for(auto a:mp){
       f=max(f,a.second);
    }
    return f;
}
    int characterReplacement(string s, int k) {
        int ans=0;
        for(int i=0;i<s.size();i++){
           for(int j=i;j<s.size();j++){
            int f=getMax(s,i,j);
            if(j-i+1-f <=k) ans=max(ans,j-i+1);
            
        } 
        }
        return ans;
    }
};
