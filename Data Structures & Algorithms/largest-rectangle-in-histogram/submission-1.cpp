class Solution {
public:
vector<int> nextSmaller(vector<int>& arr){
    int n=arr.size();
    vector<int> nextS(n,n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[i]<arr[st.top()]){
            nextS[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    return nextS;
}
vector<int> prevSmaller(vector<int>& arr){
    int n=arr.size();
    vector<int> prevS(n,-1);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[i]<arr[st.top()]){
            prevS[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    return prevS;
}
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextS=nextSmaller(heights);
        vector<int> prevS=prevSmaller(heights);
        int res=0;
        for(int i=0;i<heights.size();i++){
            int curr=heights[i]*(nextS[i]-prevS[i]-1);
            res=max(res,curr);
        }
        return res; 
    }
};
