import heapq

def is_valid(x, y, maze):
    return 0 <= x < len(maze) and 0 <= y < len(maze[0]) and maze[x][y] == 1

def astar(maze, start, end):
    directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    rows, cols = len(maze), len(maze[0])
    
    def heuristic(p1, p2):
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])
    
    open_set = [(0, start)]
    came_from = {}
    g_score = {pos: float('inf') for pos in maze}
    g_score[start] = 0
    f_score = {pos: float('inf') for pos in maze}
    f_score[start] = heuristic(start, end)
    
    while open_set:
        _, current = heapq.heappop(open_set)
        
        if current == end:
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)
            path.reverse()
            return path
        
        for dx, dy in directions:
            new_x, new_y = current[0] + dx, current[1] + dy
            neighbor = (new_x, new_y)
            
            if not is_valid(new_x, new_y, maze):
                continue
            
            tentative_g_score = g_score[current] + 1
            
            if tentative_g_score < g_score[neighbor]:
                came_from[neighbor] = current
                g_score[neighbor] = tentative_g_score
                f_score[neighbor] = g_score[neighbor] + heuristic(neighbor, end)
                if neighbor not in [item[1] for item in open_set]:
                    heapq.heappush(open_set, (f_score[neighbor], neighbor))
    
    return None

# Example usage:
maze = [
    [1, 1, 1, 0, 1],
    [1, 0, 1, 1, 1],
    [1, 0, 1, 0, 1],
    [1, 1, 1, 0, 1],
    [0, 0, 1, 1, 1]
]

start = (0, 0)
end = (4, 4)
path = astar(maze, start, end)

if path:
    print("Path found:")
    for row in range(len(maze)):
        for col in range(len(maze[0]):
            if (row, col) == start:
                print("S", end=" ")
            elif (row, col) == end:
                print("E", end=" ")
            elif (row, col) in path:
                print("*", end=" ")
            else:
                print("X" if maze[row][col] == 0 else " ", end=" ")
        print()
else:
    print("No path found.")
