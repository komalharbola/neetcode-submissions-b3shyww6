class Solution {
public:

    int characterReplacement(string s, int k) {
        int ans=0;
       
        for(char i='A';i<='Z';i++){
             int count=0,l=0,r=0;
            while(r<s.length()){
                if(s[r]==i) r++;
                else if(count <k){r++;count++;}
                else if(s[l]==i) l++;
                else {l++;count--;}
                ans=max(ans,r-l);

            }
        }
        return ans;
    }
};
