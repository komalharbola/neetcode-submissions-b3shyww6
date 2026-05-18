class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        stack<int> st;
        int n=temps.size();
        vector<int> res(n,0);
        for(int i=n-2;i>=0;i--){
            if(temps[i]<temps[i+1]){
                res[i]=1;
                st.push(i+1);
            }
            else{
                while(!st.empty() && temps[i] >= temps[st.top()])
                st.pop();
                if(!st.empty()) res[i]=st.top()-i;
            }
        }
return res;

    }
};
