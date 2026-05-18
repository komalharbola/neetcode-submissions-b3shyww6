class Solution {
public:
    bool isValid(string s) {
      stack<int> st;
      for(auto c:s){
        if(c=='(' || c=='[' || c=='{'){
            st.push(c);
        }
        else{
            if((!st.empty()) &&((c==')' && st.top()!='(') || (c==']' && st.top()!='[') || (c=='}' && st.top()!='{')))
                return false;
             else if(st.empty()) return false;
             else if(!st.empty())
        st.pop();
            
        }
       
      }
      return st.empty();  
    }
};
