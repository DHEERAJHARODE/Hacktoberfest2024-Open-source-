class TrieNode:

    def __init__(self) -> None:
        self.children = [None]*26


class Trie:

    def __init__(self) -> None:
        self.root = self.getNode()

    def getNode(self) -> TrieNode:
        return TrieNode()

    def _stringToInt(self, alphabet) -> int:
        return (ord(alphabet) - ord('a'))

    def insertAndCountsubstr(self, word) -> int:
        ans = 0

        for i in range(len(word)):
            crawl = self.root
            for j in word[i:]:
                ind = self._stringToInt(j)

                if not crawl.children[ind]:
                    crawl.children[ind] = self.getNode()
                    ans += 1

                crawl = crawl.children[ind]

        # +1 for empty substring
        return (ans + 1)


trie = Trie()
print(trie.insertAndCountsubstr('udbhav'))
