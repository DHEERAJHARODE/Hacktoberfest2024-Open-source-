#include <unordered_map>
#include <iostream>

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool is_end_of_word;
    
    TrieNode() : is_end_of_word(false) {}
};

class Trie {
public:
    TrieNode* root;
    
    Trie() { root = new TrieNode(); }
    
    void insert(std::string word) {
        TrieNode* node = root;
        for(char ch : word) {
            if(!node->children.count(ch))
                node->children[ch] = new TrieNode();
            node = node->children[ch];
        }
        node->is_end_of_word = true;
    }
    
    bool search(std::string word) {
        TrieNode* node = root;
        for(char ch : word) {
            if(!node->children.count(ch))
                return false;
            node = node->children[ch];
        }
        return node && node->is_end_of_word;
    }
};

int main() {
    Trie trie;
    trie.insert("hello");
    std::cout << trie.search("hello") << std::endl;  // Output: 1
    std::cout << trie.search("hell") << std::endl;   // Output: 0
    return 0;
}
