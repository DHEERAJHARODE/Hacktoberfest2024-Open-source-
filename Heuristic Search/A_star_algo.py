import heapq

def a_star_search(graph, start, goal, heuristic, cost):
    # Priority queue to select the best node based on f(n) = g(n) + h(n)
    pq = [(heuristic[start], start, 0)]  # (f(n), current_node, g(n))
    visited = set()
    path = {}

    while pq:
        f_value, current_node, g_value = heapq.heappop(pq)

        if current_node in visited:
            continue
        visited.add(current_node)

        # Check if we've reached the goal
        if current_node == goal:
            print(f"Goal {goal} reached.")
            return reconstruct_path(path, start, goal)

        # Explore neighbors
        for neighbor in graph[current_node]:
            tentative_g_value = g_value + cost[(current_node, neighbor)]
            if neighbor not in visited:
                path[neighbor] = current_node
                f_value = tentative_g_value + heuristic[neighbor]
                heapq.heappush(pq, (f_value, neighbor, tentative_g_value))

    print("Goal not reachable.")
    return None

def reconstruct_path(path, start, goal):
    current = goal
    full_path = []
    while current != start:
        full_path.append(current)
        current = path[current]
    full_path.append(start)
    return full_path[::-1]

# Example usage
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['G'],
    'F': ['G'],
    'G': []
}

cost = {
    ('A', 'B'): 1, ('A', 'C'): 3,
    ('B', 'D'): 3, ('B', 'E'): 1,
    ('C', 'F'): 2, ('E', 'G'): 2,
    ('F', 'G'): 1
}

heuristic = {
    'A': 6, 'B': 4, 'C': 5, 'D': 2, 'E': 2, 'F': 4, 'G': 0
}

path = a_star_search(graph, 'A', 'G', heuristic, cost)
print("Path:", path)
