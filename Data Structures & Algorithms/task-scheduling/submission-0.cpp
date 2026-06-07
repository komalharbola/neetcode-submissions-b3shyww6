class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);
        int mx=0;
        int count=0;
        for(auto c: tasks){
            freq[c-'A']++;
            mx=max(mx,freq[c-'A']);
        }
        for(auto f:freq){
            if(f==mx) count++;
        }
        int ans= (mx-1)*(n+1)+count;
        return max(ans,static_cast<int>(tasks.size()));
    }
};
