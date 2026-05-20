class TimeMap {
public:
unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
       mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end())return "";
        int res=-1;
        vector<pair<int,string>> vals=mp[key];
        int lo=0,hi=vals.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(vals[mid].first <=timestamp){ lo=mid+1;
            res=mid;}
            else{
                hi=mid-1;
            }
        }
        return res==-1?"":vals[res].second;
    }
};
