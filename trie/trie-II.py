class TrieNode:

    def __init__(self) -> None:
        self.children = [None]*26
        self.end = False
        self.countEnd = 0
        self.countPrefix = 0


class Trie:

    def __init__(self) -> None:
        self.root = self.getNode()

    def getNode(self) -> None:
        return TrieNode()

    def _stringToInt(self, alphabet) -> int:
        return (ord(alphabet) - ord('a'))

    def insert(self, word) -> None:
        crawl = self.root

        for i in word:
            ind = self._stringToInt(i)

            if not crawl.children[ind]:
                crawl.children[ind] = self.getNode()

            crawl = crawl.children[ind]
            crawl.countPrefix += 1

        crawl.end = True
        crawl.countEnd += 1
        # print(f"Inserted {word}.")

    def countWords(self, word) -> int:
        crawl = self.root

        for i in word:
            ind = self._stringToInt(i)

            if not crawl.children[ind]:
                return 0

            crawl = crawl.children[ind]

        return crawl.countEnd

    def countStartsWith(self, string) -> int:
        crawl = self.root

        for i in string:
            ind = self._stringToInt(i)

            if not crawl.children[ind]:
                return 0

            crawl = crawl.children[ind]

        return crawl.countPrefix

    def erase(self, word) -> None:
        crawl = self.root

        for i in word:
            ind = self._stringToInt(i)
            crawl = crawl.children[ind]
            crawl.countPrefix -= 1

        crawl.countEnd -= 1
        crawl.end = False

        print(f"Deleted {word}.")


def display(trieRoot, string=""):
    crawl = trieRoot

    if crawl.end:
        print(f"{string} ({crawl.countEnd})", end=" ")

    for i in range(26):
        if crawl.children[i] != None:
            display(crawl.children[i], string+chr(ord('a')+i))


trie = Trie()
trie.insert("apple")
trie.insert("apple")
trie.insert("apps")
trie.insert("appe")
trie.insert("app")
trie.insert("udbhav")
trie.insert("bunny")
trie.insert("umbrella")
print(trie.countStartsWith("apps"))
print(trie.countStartsWith("a"))
print(trie.countWords("a"))
print(trie.countWords("apple"))
display(trie.root)
print()
trie.erase("apple")
trie.erase("appe")
print(trie.countWords("apple"))
print(trie.countStartsWith("a"))
display(trie.root)
