#include <bits/stdc++.h>
using namespace std;

vector< vector <int>> g;
vector<bool> v;

// Undirected graph
void addEdge(int a, int b)
{
	g[a].push_back(b);
	//g[b].push_back(a);
}

void dfsVisit(int u)
{
	v[u] = true;
	cout << u << " ";

	for(auto i = g[u].begin(); i != g[u].end(); i++)
	{
		if(!v[*i])
			dfsVisit(*i);
	}
}

void dfs(int n)
{
	for(int u = 0; u < n; u++)
	{
		if(!v[u])
			dfsVisit(u);
	}
}

int main()
{
	int n, e;
	cin >> n >> e;

	v.assign(n, false);
	g.assign(n, vector<int>());

	int a, b;
	for(int i = 0; i < e; i++)
	{
		cin >> a >> b;
		addEdge(a, b);
	}

	dfs(n);
}
