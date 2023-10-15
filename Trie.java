public class Trie {

    private TrieNode root;

    public Trie() {
        this.root = new TrieNode();
    }

    public void insert(String word) {
        TrieNode current = root;
        for (char character : word.toCharArray()) {
            TrieNode child = current.children.get(character);
            if (child == null) {
                child = new TrieNode();
                current.children.put(character, child);
            }
            current = child;
        }
        current.isWord = true;
    }

    public boolean search(String word) {
        TrieNode current = root;
        for (char character : word.toCharArray()) {
            TrieNode child = current.children.get(character);
            if (child == null) {
                return false;
            }
            current = child;
        }
        return current.isWord;
    }

    public boolean startsWith(String prefix) {
        TrieNode current = root;
        for (char character : prefix.toCharArray()) {
            TrieNode child = current.children.get(character);
            if (child == null) {
                return false;
            }
            current = child;
        }
        return true;
    }

    private class TrieNode {

        private char character;
        private HashMap<Character, TrieNode> children;
        private boolean isWord;

        public TrieNode() {
            this.children = new HashMap<>();
            this.isWord = false;
        }
    }
}
Use code with caution. Learn more
To use the Trie data structure, we can simply create a new instance of the Trie class and call the insert(), search(), and startsWith() methods as needed. For example, the following code inserts the words "hello", "world", and "helloworld" into a trie and then searches for the word "helloworld":

Java
Trie trie = new Trie();

trie.insert("hello");
trie.insert("world");
trie.insert("helloworld");

boolean found = trie.search("helloworld");

System.out.println(found); // true
