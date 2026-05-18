class MinStack {
public:
  stack<int> st1;
  stack<int> st2;

    MinStack() {
        
    }
    
    void push(int val) {
     if(st1.empty())
        st2.push(val);
     
     else if(val<st2.top()) st2.push(val);
     else st2.push(st2.top());
        
     st1.push(val); 
        
    }
    
    void pop() {
        if(!st1.empty()){
        st1.pop();
        st2.pop();}
        
    }
    
    int top() {
        if(!st1.empty())
      return st1.top(); 
      return 0;
    }
    
    int getMin() {
        if(!st2.empty())
      return  st2.top();
      return 0;
    }
};
