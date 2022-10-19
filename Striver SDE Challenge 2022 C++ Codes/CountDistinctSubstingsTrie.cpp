struct Node {
    Node *links[26];
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
};
class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    int countDistinctSubstrings(string word) {
        int cnt=1;
        for(int j=0;j<word.size();j++){
            Node *node = root;
            for (int i = j; i < word.size(); i++) {
                if (!node->containsKey(word[i])) {
                    node->put(word[i], new Node());
                    cnt++;
                }
                node = node->get(word[i]);
            }
        }
        return cnt;
    }
};
int countDistinctSubstrings(string &s)
{
    Trie trie;
    return trie.countDistinctSubstrings(s);
}