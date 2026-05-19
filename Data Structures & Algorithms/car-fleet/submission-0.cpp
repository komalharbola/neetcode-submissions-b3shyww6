class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       int n=position.size();
        vector<int> indices(n);
        iota(indices.begin(),indices.end(),0);
        sort(indices.begin(),indices.end(),[&](int i,int j) {return position[i]>position[j];});
        int count=0;
        double prev=0.0;
        for(auto i:indices){
            double curr=static_cast<double>(target-position[i])/speed[i];
            if(curr>prev){
                count++;
                prev=curr;
            }
        }
        return count;
    }
};
