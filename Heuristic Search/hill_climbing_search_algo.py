def hill_climbing(graph, start, goal, heuristic):
    current_node = start
    visited = set()

    while current_node != goal:
        visited.add(current_node)

        # Find the neighbor with the lowest heuristic value
        neighbors = graph[current_node]
        next_node = None
        lowest_heuristic = float('inf')
        for neighbor in neighbors:
            if neighbor not in visited and heuristic[neighbor] < lowest_heuristic:
                lowest_heuristic = heuristic[neighbor]
                next_node = neighbor

        # If no improvement is possible, return failure
        if next_node is None or heuristic[next_node] >= heuristic[current_node]:
            print("Stuck at local maxima. Goal not reachable.")
            return None

        current_node = next_node
        print(f"Moved to {current_node}, heuristic = {heuristic[current_node]}")

    print(f"Goal {goal} reached.")
    return current_node

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

heuristic = {
    'A': 6, 'B': 4, 'C': 5, 'D': 2, 'E': 2, 'F': 4, 'G': 0
}

hill_climbing(graph, 'A', 'G', heuristic)
