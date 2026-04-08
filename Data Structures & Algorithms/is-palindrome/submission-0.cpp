class Solution {
public:
    bool isPalindrome(string s) {
        int st=0,ed=s.length()-1;
        if(!isalpha(s[ed])) ed--;
        while(st < ed){
             while (st < ed && !isalnum(s[st])) {
                st++;
            }
            while (ed > st && !isalnum(s[ed])) {
                ed--;
            }
            if(tolower(s[st]) != tolower(s[ed])) return false;

            
            

            st++;
            ed--;
        }
        return true;
    }
};
