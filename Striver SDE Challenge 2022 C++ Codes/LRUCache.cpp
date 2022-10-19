class LRUCache {
public:
    class node {
      public:
        int key;
      int val;
      node * next;
      node * prev;
      node(int _key, int _val) {
        key = _key;
        val = _val;
      }
    };
    
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    int cap;
    unordered_map<int, node *>umap;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    //add node after head
    void addNode(node *newN){
        newN->next=head->next;
        head->next->prev=newN;
        head->next=newN;
        newN->prev=head;
    }
    
    void delNode(node *delN){
        delN->next->prev=delN->prev;
        delN->prev->next=delN->next;
    }
    
    int get(int key_) {
        if(umap.find(key_)!=umap.end()){
            node *res = umap[key_];
            int ans=res->val;
            
            umap.erase(key_);//removed from map
            delNode(res);//removed from doubly
            addNode(res);//added to next of head for recently used
            umap[key_]=head->next;//added to map with latest position
            
            return ans;
        }
        return -1; //key not present
    }
    
    void put(int key_, int value) {
        if(umap.find(key_)!=umap.end()){
            node *rem=umap[key_];
            umap.erase(key_);//removed from map
            delNode(rem);//removed from doubly
        }
        if(umap.size()==cap){
            umap.erase(tail->prev->key);
            delNode(tail->prev);
        }
        
        addNode(new node(key_,value));//added to next of head for recently used
        umap[key_]=head->next;//added to map with latest position
    }
};