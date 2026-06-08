class MedianFinder {
    private:
    priority_queue<int, vector<int>> mx;
    priority_queue<int, vector<int>,greater<int>> mn;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        mx.push(num);
        mn.push(mx.top());
        mx.pop();
        if(mx.size()+1 < mn.size()){
            mx.push(mn.top());
            mn.pop();
        }
    }
    
    double findMedian() {
        if(mn.size()== mx.size()){
            return ((mn.top()+mx.top())/2.0);
        }
        return mn.top();
    }
};
