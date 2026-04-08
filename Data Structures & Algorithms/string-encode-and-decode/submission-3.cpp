class Solution {
public:
string encode(vector<string>& strs) {
       string ans;
      int leng;
       for(auto s:strs){
        leng = s.size();
        ans += to_string(leng);
        ans += ' ';
       
           ans += s;
       
      
       }
      
       return ans;
    }

 vector<string> decode(string s) {
    vector<string> res;
    string ans;
    for(int i=0;i<s.length();){
    int len=0;

      while(s[i] !=' '){
        len= len*10 +(s[i]-'0');
        i++;
}
i++;
       res.push_back(s.substr(i,len));
      //  res.push_back(s);
      
       i+=len;
}
return res;
    }
};
