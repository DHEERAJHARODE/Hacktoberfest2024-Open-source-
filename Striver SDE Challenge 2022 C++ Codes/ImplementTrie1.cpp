struct Node{
        Node *links[26];
        bool flag=false;
        
        bool containsKey(char c){
            return (links[c-'a'] != NULL);
        }
        
        void put(char c, Node* node){
            links[c-'a'] = node;
        }
        
        Node* get(char c){
            return links[c-'a'];
        }
        
        void setEnd(){
            flag=true;
        }
        
        bool isEnd(){
            return flag;
        }
    };
class Trie {
public:    
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            //if trie for this char doesnt exist
            if(!node->containsKey(word[i])){
                //then create trie for it in a new node
                node->put(word[i], new Node());
            }
            //if trie present, move to that trie
            node = node->get(word[i]);
        }
        //set flag true to mark word end at this trie
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};