class KthLargest {
public:
vector<int> arr;
int i;
    KthLargest(int k, vector<int>& nums) {
        arr=nums;
        i=k;
    }
    
    int add(int val) {
        arr.push_back(val);
        if(arr.size() <i) return -1;
        sort(arr.begin(),arr.end());
        int idx=arr.size()-i;
        return arr[idx];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */