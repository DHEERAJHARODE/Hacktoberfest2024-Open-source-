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

    def getMaxXor(self, num) -> int:
        crawl = self.root
        ans = 0

        for i in range(31, -1, -1):
            bit = (num >> i) & 1

            if crawl.children[1-bit]:
                ans = ans | (1 << i)
                crawl = crawl.children[1-bit]

            else:
                crawl = crawl.children[bit]
        
        return ans

l = [0, 1, 2, 3, 4]
q = [[1, 3], [5, 6]]

n = len(q)
ans = [-1]*n

offlineQueries = []
for i in range(n):
    offlineQueries.append([q[i][1], q[i][0], i])
offlineQueries.sort()
l.sort()
j = 0

trie = Trie()
for i in offlineQueries:
    while j < len(l) and l[j] <= i[0]:
        trie.insert(l[j])
        j += 1
    ans[i[2]] = trie.getMaxXor(i[1])

for i in ans:
    print(i)
