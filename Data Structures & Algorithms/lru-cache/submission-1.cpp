class LRUCache {
private:
unordered_set<int> inDq;
unordered_map<int,int> cache;
int capacity;
deque<int> dq;
public:

    LRUCache(int capacity):capacity(capacity) {
        
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()){
            return -1;
        }
      if(inDq.count(key)){
        auto it= find(dq.begin(),dq.end(),key);
        dq.erase(it);}
        dq.push_back(key);
        inDq.insert(key);
        return cache[key];
      
      
    }
    
    void put(int key, int value) {
        cache[key]=value;
        if(inDq.count(key)){
          
           auto it=find(dq.begin(),dq.end(),key);
           dq.erase(it);

        }
        dq.push_back(key);
        inDq.insert(key);
        if(cache.size()>capacity){
            auto lru=dq.front();
            dq.pop_front();
            cache.erase(lru);
            inDq.erase(lru);
        }
    }
};
