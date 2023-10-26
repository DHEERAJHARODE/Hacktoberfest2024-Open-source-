class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)

        if root_x != root_y:
            if self.rank[root_x] > self.rank[root_y]:
                self.parent[root_y] = root_x
            else:
                self.parent[root_x] = root_y
                if self.rank[root_x] == self.rank[root_y]:
                    self.rank[root_y] += 1

def kruskal(graph):
    edges = [(weight, u, v) for u, adjacent in graph.items() for v, weight in adjacent]
    edges.sort()

    mst = []
    uf = UnionFind(len(graph))

    for weight, u, v in edges:
        if uf.find(u) != uf.find(v):
            mst.append((u, v, weight))
            uf.union(u, v)

    return mst

# Example usage:
graph = {
    'A': [('B', 2), ('C', 3)],
    'B': [('A', 2), ('C', 1), ('D', 1)],
    'C': [('A', 3), ('B', 1), ('D', 2)],
    'D': [('B', 1), ('C', 2)]
}

minimum_spanning_tree = kruskal(graph)
for u, v, weight in minimum_spanning_tree:
    print(f'Edge: {u} - {v}, Weight: {weight}')
