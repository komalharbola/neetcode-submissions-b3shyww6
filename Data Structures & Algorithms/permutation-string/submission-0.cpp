class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int>s1Freq(26,0);
        vector<int>windowFreq(26,0);
        int winSize=s1.size();
        for(auto c:s1) s1Freq[c-'a']++;
        for(int i=0;i<s2.size();i++){
              windowFreq[s2[i]-'a']++;
              if(i>=winSize)windowFreq[s2[i-winSize]-'a']--;
              if(s1Freq==windowFreq) return true;
        }
        return false;
    }
};
