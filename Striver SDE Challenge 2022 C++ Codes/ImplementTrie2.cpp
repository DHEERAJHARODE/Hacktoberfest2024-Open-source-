struct Node{
    Node* links[26];
    int ew=0,c=0;
    
    bool containsKey(char ch){
        return(links[ch-'a'] != NULL);
    }
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void incEndsWith(){
        ew++;
    }
    void decEndsWith(){
        ew--;
    }
    void incCount(){
        c++;
    }
    void decCount(){
        c--;
    }
};
class Trie{

    public:
    Node* root;
    Trie(){
        root= new Node();
    }

    void insert(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            //else
            node = node->get(word[i]);
            node->incCount();
        }
        node->incEndsWith();
    }

    int countWordsEqualTo(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->ew;
    }

    int countWordsStartingWith(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->c;
    }

    void erase(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                node->decCount();
            }
        }
        node->decEndsWith();
    }
    
};
