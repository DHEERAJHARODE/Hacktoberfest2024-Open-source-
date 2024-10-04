import heapq

def best_first_search(graph, start, goal, heuristic):
    # Priority queue to select the best node based on the heuristic value
    pq = [(heuristic[start], start)]
    visited = set()

    while pq:
        _, current_node = heapq.heappop(pq)
        
        if current_node in visited:
            continue
        visited.add(current_node)

        # Check if we've reached the goal
        if current_node == goal:
            print(f"Goal {goal} reached.")
            return

        # Explore neighbors
        for neighbor in graph[current_node]:
            if neighbor not in visited:
                heapq.heappush(pq, (heuristic[neighbor], neighbor))

    print("Goal not reachable.")

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

best_first_search(graph, 'A', 'G', heuristic)
