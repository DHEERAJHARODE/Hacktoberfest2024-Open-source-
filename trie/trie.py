class TrieNode:

    def __init__(self):
        self.children = [None]*26
        self.end = False

    def isEnd(self):
        if self.end:
            return True
        return False


class trie:

    def __init__(self):
        self.root = self.getNode()

    def getNode(self):
        return TrieNode()

    def _charToIndex(self, ch):
        return ord(ch)-ord('a')

    # tc -> O(len(word))
    def insert(self, word):
        crawl = self.root

        for i in word:
            ind = self._charToIndex(i)

            if not crawl.children[ind]:
                crawl.children[ind] = self.getNode()
            crawl = crawl.children[ind]

        crawl.end = True

    # tc -> O(len(word))
    def search(self, word):
        crawl = self.root

        for i in word:
            ind = self._charToIndex(i)

            if not crawl.children[ind]:
                return False

            crawl = crawl.children[ind]

        return crawl.end

    # tc -> O(len(prefix))
    def starsWith(self, prefix):
        crawl = self.root

        for i in prefix:
            ind = self._charToIndex(i)

            if not crawl.children[ind]:
                return False

            crawl = crawl.children[ind]

        qty = sum(1 for i in range(len(crawl.children))
                  if crawl.children[i] != None)
        if crawl.isEnd():
            qty += 1
        return (True, qty)


n = trie()
n.insert('udbhav')
n.insert('bruhhhh')
n.insert('bunny')
n.insert('apple')
n.insert('appe')
n.insert('appes')
n.insert('appeusy')
n.insert('appeo')
print(n.search('bunn'))
print(n.search('bunny'))
print(n.starsWith('app'))
print(n.starsWith('appe'))
print(n.starsWith('udbhav'))
print(n.starsWith('bunn'))
