#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
using namespace std;

// A class to represent a graph
class Graph {
    int V; // Number of vertices
    vector<vector<int>> capacity; // Capacity of edges
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int V) : V(V), capacity(V, vector<int>(V, 0)), adj(V) {}

    // Function to add an edge to the graph
    void addEdge(int u, int v, int cap) {
        capacity[u][v] = cap;
        adj[u].push_back(v);
        adj[v].push_back(u); // Add reverse edge for residual graph
    }

    // A breadth-first search to check if there is a path from source to sink
    bool bfs(vector<vector<int>>& residual, int s, int t, vector<int>& parent) {
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(s);
        visited[s] = true;
        parent[s] = -1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (!visited[v] && residual[u][v] > 0) {
                    parent[v] = u;
                    if (v == t) return true;
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        return false;
    }

    // Ford-Fulkerson algorithm for computing maximum flow
    int fordFulkerson(int source, int sink) {
        int u, v;
        vector<vector<int>> residual = capacity;
        vector<int> parent(V);
        int maxFlow = 0;

        // Augment flow while there is a path from source to sink
        while (bfs(residual, source, sink, parent)) {
            cout << "Path found from " << source << " to " << sink << endl; // Debug output
            int pathFlow = INT_MAX;

            // Find the maximum flow through the path found.
            for (v = sink; v != source; v = parent[v]) {
                u = parent[v];
                pathFlow = min(pathFlow, residual[u][v]);
            }

            // Update residual capacities of the edges and reverse edges
            for (v = sink; v != source; v = parent[v]) {
                u = parent[v];
                residual[u][v] -= pathFlow;
                residual[v][u] += pathFlow;
            }

            // Add path flow to overall flow
            maxFlow += pathFlow;
        }

        cout << "The maximum possible flow is " << maxFlow << endl;
        printFlowValues(residual, source);
        printMinCut(residual, source);

        return maxFlow;
    }

    // Print the flow values along the edges
    void printFlowValues(const vector<vector<int>>& residual, int source) {
        cout << "Flow values along the edges: " << endl;
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                if (capacity[u][v] > 0 && residual[u][v] < capacity[u][v]) {
                    cout << "Edge (" << u << " -> " << v << "): Flow = "
                         << capacity[u][v] - residual[u][v] << " / Capacity = " << capacity[u][v] << endl;
                }
            }
        }
    }

    // Use DFS to print the edges that define the minimum cut
    void printMinCut(const vector<vector<int>>& residual, int source) {
        vector<bool> visited(V, false);
        dfs(residual, source, visited);

        cout << "Edges in the Minimum Cut: " << endl;
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                if (visited[u] && !visited[v] && capacity[u][v]) {
                    cout << u << " -> " << v << endl;
                }
            }
        }
    }

    // DFS for marking reachable vertices
    void dfs(const vector<vector<int>>& residual, int u, vector<bool>& visited) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v] && residual[u][v] > 0) {
                dfs(residual, v, visited);
            }
        }
    }

    int size() const { return V; } // Function to get the number of vertices
};

int main() {
    // Define the number of vertices
    int V = 4; // Example: 4 vertices

    // Create a graph
    Graph g(V);

    // Define edges and their capacities (example edges)
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 5);
    g.addEdge(1, 2, 15);
    g.addEdge(1, 3, 10);
    g.addEdge(2, 3, 10);

    cout << "Graph created with " << g.size() << " vertices." << endl;

    int source = 0; // Assuming source node is 0
    int sink = g.size() - 1; // Assuming sink node is the last node

    cout << "Running Ford-Fulkerson from source " << source << " to sink " << sink << "..." << endl;
    g.fordFulkerson(source, sink);

    return 0;
}
