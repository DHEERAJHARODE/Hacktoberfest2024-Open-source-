def floyd_warshall(graph):
    num_vertices = len(graph)
    
    # Initialize the distance matrix with the graph's adjacency matrix
    # Initialize the path matrix with an empty matrix
    dist = [[float('inf')] * num_vertices for _ in range(num_vertices)]
    path = [[None] * num_vertices for _ in range(num_vertices)]
    
    for i in range(num_vertices):
        for j in range(num_vertices):
            if i == j:
                dist[i][j] = 0
            elif graph[i][j] != 0:
                dist[i][j] = graph[i][j]
                path[i][j] = i
    
    # Main algorithm
    for k in range(num_vertices):
        for i in range(num_vertices):
            for j in range(num_vertices):
                if dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
                    path[i][j] = path[k][j]
                    
    return dist, path

def print_shortest_path(path, i, j):
    if i == j:
        print(i, end=" ")
    elif path[i][j] is None:
        print("No path exists")
    else:
        print_shortest_path(path, i, path[i][j])
        print(j, end=" ")

# Example usage
graph = [
    [0, 3, 0, 0, 0, 0],
    [0, 0, 1, 0, 0, 0],
    [0, 0, 0, 7, 0, 2],
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 2, 0, 0],
    [0, 0, 0, 0, 1, 0]
]

distances, paths = floyd_warshall(graph)

# Print shortest paths between all pairs of vertices
for i in range(len(graph)):
    for j in range(len(graph)):
        if i != j:
            print(f"Shortest path from {i} to {j}: ", end="")
            print_shortest_path(paths, i, j)
            print(f", Distance: {distances[i][j]}")
