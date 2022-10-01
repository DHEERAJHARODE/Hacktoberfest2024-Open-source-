class TrieNode:

    def __init__(self) -> None:
        self.children = [None]*26
        self.end = False


class Trie:

    def __init__(self) -> None:
        self.root = self.getNode()

    def getNode(self) -> TrieNode:
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

        crawl.end = True

    def isPresent(self, string) -> bool:
        crawl = self.root

        for i in string:
            ind = self._stringToInt(i)

            if not crawl.children[ind]:
                return False

            crawl = crawl.children[ind]

        return crawl.end

    def isCompleteString(self, string) -> bool:
        crawl = self.root

        for i in string:
            ind = self._stringToInt(i)

            if not crawl.children[ind]:
                return False

            crawl = crawl.children[ind]

            if crawl.end == False:
                return False
        
        return crawl.end

    def longestWordWithAllPrefixes(self, wordList) -> str:
        ans = 0
        for i in wordList:
            if self.isCompleteString(i):
                ans = max(ans, len(i))
        return ans


trie = Trie()
l = ['n', 'ninja', 'ninj', 'ni', 'nin', 'ninga']

for i in l:
    trie.insert(i)

print(trie.longestWordWithAllPrefixes(l))

longest = ''
for i in l:
    if trie.isCompleteString(i):
        if len(i) > len(longest):
            longest = i
        elif len(i) == len(longest) and i < longest:
            longest = i
print(longest)