// Count number of nodes in a level (BFS)

#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int bfs(vector<int> adj[], int s, int l, int V)
{
	bool *visited = new bool[V];
	int level[V];

	for(int i = 0; i < V; i++)
	{
		visited[i] = false;
		level[i] = 0;
	}

	list<int> queue;

	visited[s] = true;
	queue.push_back(s);
	level[s] = 0;

	while(!queue.empty())
	{
		s = queue.front();
		queue.pop_front();
		cout << s << " ";
		for(auto i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if(!visited[*i])
			{
				level[*i] = level[s]+1;
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}

	int count = 0;
	for(int i = 0; i < V; i++)
	{
		if(level[i] == l)
		{
			count++;
		}
	}
	return count;
}

int main() {
	int V = 6;
	vector<int> adj[V];

	addEdge(adj, 0, 1); 
    addEdge(adj, 0, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 2, 4); 
    addEdge(adj, 2, 5);
    cout << bfs(adj, 0, 2, V); 
}