class LRUCache {
private:
    struct Node{
        int key,val;
        Node* next;
        Node* prev;
        Node(int k,int v):key(k),val(v){}
    };
    unordered_map<int,Node*> cache;
    Node* head;
    Node* tail;
    int capacity;
    void add(Node* node){
        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;
    }
    void remove(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
public:
    LRUCache(int capacity):capacity(capacity) {
         head=new Node(0,0);
         tail=new Node(0,0);
         head->next=tail;
         tail->prev=head;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            remove(node);
            add(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            Node* node=cache[key];
            node->val=value;
            remove(node);
            add(node);
        }
        else{
            Node* node = new Node(key,value);
            cache[key]=node;
            add(node);
            if(cache.size()>capacity){
                Node* rm = tail->prev;
                remove(rm);
                cache.erase(rm->key);
                delete rm;
            }
        }
    }
};
