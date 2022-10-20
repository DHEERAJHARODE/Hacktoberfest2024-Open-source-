#include <bits/stdc++.h>
using namespace std;
int chromatic_number = INT_MAX, total_possible_soln = 0;
struct Edge
{ int src, dest;};
class Graph
{
public:
    vector<vector<int>> adj;
    Graph(vector<Edge> const &edges, int n)
    {
        adj.resize(n);
        for (Edge edge : edges)
        {
            int src = edge.src;
            int dest = edge.dest;
            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }
    }
};
string COLORS[] = {"", "GREEN", "RED", "BLACK", "YELLOW", "ORANGE",
                   "PINK", "BLUE", "BROWN", "WHITE", "PURPLE"};
bool isSafe(Graph const &graph, vector<int> color, int v, int c)
{
    for (int u : graph.adj[v])
    {  if (color[u] == c)
          return false;
    }
    return true;
}
void kColorable(Graph const &graph, vector<int> &color, int k, int v, int n)
{
    if (v == n)
    {
        int temp = 0;
        total_possible_soln++;
        map<string, int> m;
        for (int v = 0; v < n; v++)
        {
            cout << setw(8) << left << COLORS[color[v]];
            if (m[COLORS[color[v]]] == 0)
            {temp++;m[COLORS[color[v]]]++;}
        }
        if (chromatic_number > temp)
            chromatic_number = temp;
        cout << endl;
        return;
    }
    for (int c = 1; c <= k; c++)
    {
        if (isSafe(graph, color, v, c))
        {
            color[v] = c;
            kColorable(graph, color, k, v + 1, n);
            color[v] = 0;
        }
    }
}
int main()
{
    vector<Edge> edges = {
        {0, 4}, {0, 1}, {0, 3}, {1, 4}, {1, 4}, {2, 3}, {2, 4}};
    int n = 5;
    Graph g(edges, n);
    int k = 3;
    vector<int> color(n, 0);
    cout << "1\t2\t3\t4\t5" << endl;
    kColorable(g, color, k, 0, n);
    cout << "Minimum colors:- " << chromatic_number << endl;
    cout << "Total Number of ways:- " << total_possible_soln << endl;
    return 0;
}