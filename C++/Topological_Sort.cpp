#include <bits/stdc++.h>
using namespace std;

void dfsSort(int v, vector<vector<int>>& adj,
              vector<bool>& visited,
              stack<int>& Stack)
{
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all adjacent vertices
    for (int i : adj[v]) {
        if (!visited[i])
            dfsSort(i, adj, visited, Stack);
    }

    // Push current vertex to stack which stores the result
    Stack.push(v);
}

// Function to perform Topological Sort
void topoSort(vector<vector<int>>& adj, int V)
{
    stack<int> Stack; 
    vector<bool> visited(V, false);
   
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfsSort(i, adj, visited, Stack);
    }
   
    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main()
{
    // Number of nodes
    int V = 4;

    // Edges
    vector<vector<int>> edges = { { 0, 1 }, { 1, 2 }, { 3, 1 }, { 3, 2 } };

    // Graph represented as an adjacency list
    vector<vector<int>> adj(V);

    for (auto i : edges) {
        adj[i[0]].push_back(i[1]);
    }

    cout << "Topological sorting of the graph: ";
    topoSort(adj, V);

    return 0;
}