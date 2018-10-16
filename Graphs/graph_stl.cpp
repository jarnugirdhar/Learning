#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void dfs_util(int u, vector<int> adj[], vector<bool> &visited)
{
	visited[u] = true;

	cout << u << " ";

	for(int i = 0; i < adj[u].size(); i++)
	{
		if(visited[adj[u][i]] == false)
		{
			dfs_util(adj[u][i], adj, visited);
		}
	}
}

void dfs(vector<int> adj[], int V)
{
	vector<bool> visited(V, false);
	for(int u = 0; u < V; u++)
	{
		if(visited[u] == false)
		{
			dfs_util(u, adj, visited);
		}
	}
}

int main()
{
	int V = 6;
	vector<int> adj[V];

	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 1, 3);
	addEdge(adj, 2, 4);
	addEdge(adj, 2, 5);

	dfs(adj, V);
	return 0;
}