struct Node {
    Node *links[26];
    bool flag = false;
    //checks if the reference trie is present or not
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }
    //creating reference trie
    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }
    //to get the next node for traversal
    Node *get(char ch) {
        return links[ch - 'a'];
    }
    //setting flag to true at the end of the word
    void setEnd() {
        flag = true;
    }
    //checking if the word is completed or not
    bool isEnd() {
        return flag;
    }
};
class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool containsPrefix(string st){
        Node *node =root;
        for(int i=0;i<st.size();i++){
            if(node->containsKey(st[i])){
                node = node->get(st[i]);
                //every trie must end with true trie for ans word
                if (node->isEnd()==false) return false;
            }
            else return false;
        }
        return true;
    }
};
string completeString(int n, vector<string> &a){
    //create Trie class obj
    Trie trie;
    //insert words
    for(auto &it: a){
        trie.insert(it);
    }
    //find longest/ans
    string ans="";
    for(auto &it: a){
        if(trie.containsPrefix(it)){
            if(it.size()>ans.size()) ans=it;
            else if(it.size()==ans.size() and it<ans) ans=it;//checking lexico
        }
    }
    return ans==""?"None":ans;
}