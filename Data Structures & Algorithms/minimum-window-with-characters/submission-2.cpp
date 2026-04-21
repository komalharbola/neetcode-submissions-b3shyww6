class Solution {
public:
    bool compare (string p,string t){
       vector<int> freq(256,0);  
      for(auto c:t)freq[c]++;
      for(auto c:p){
        if(freq[c]>0)freq[c]--;
      }  
      for(auto a:freq)if(a !=0) return false;
      return true;
    }
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        if(s==t)return t;
        int minSize=s.size();
        string ans="";
        int n=s.size();
       
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
              string str= s.substr(i,j-i+1);
              if(compare(str,t)){
                if(minSize>=j-i+1){ 
                    minSize=j-i+1;
                    ans=str;

                }
              } 
            }
        }
     return ans;
    
       
    }
};
