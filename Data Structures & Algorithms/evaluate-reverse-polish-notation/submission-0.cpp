class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto t:tokens){
            if(t=="+" || t=="-" || t=="/" || t=="*"){
                int sec=st.top();
                st.pop();
                int first=st.top();
                st.pop();
                int res=0;
                if(t=="+") res=first+sec;
               else if(t=="-") res=first-sec;
                else if(t=="/") res=first/sec;
                else res=first*sec;
                st.push(res);
            }
            else
                st.push(stoi(t));
            
        }
        return st.top();
    }
};
