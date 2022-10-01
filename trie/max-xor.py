class TrieNode:

    def __init__(self) -> None:
        self.children = [None]*2
        self.end = False


class Trie:

    def __init__(self) -> None:
        self.root = self.getNode()

    def getNode(self) -> None:
        return TrieNode()

    def insert(self, num) -> None:
        crawl = self.root

        for i in range(31, -1, -1):
            bit = (num >> i) & 1
            if not crawl.children[bit]:
                crawl.children[bit] = self.getNode()

            crawl = crawl.children[bit]

        crawl.end = True

    def getXorMax(self, numList) -> int:
        maxnum = 0
        for num in numList:
            crawl = self.root
            for j in range(31, -1, -1):
                bit = (num >> j) & 1

                if crawl.children[1 - bit]:
                    maxnum = maxnum | (1 << j)
                    crawl = crawl.children[1 - bit]

                else:
                    crawl = crawl.children[bit]

        return maxnum


def display(trieRoot, string=""):
    crawl = trieRoot

    if crawl.end:
        print(f"{string}", end=" ")

    for i in range(2):
        if crawl.children[i] != None:
            display(crawl.children[i], string+str(i))


trie = Trie()

x = [6, 8]
y = [7, 8, 2]
for i in y:
    trie.insert(i)

display(trie.root)
print(trie.getXorMax(x))
