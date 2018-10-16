#include <iostream>
#include <list>

using namespace std;

class Graph
{
	int V;
	list<int>* adj;
	void dfs_util(int v, bool visited[]);
public:
	Graph(int V); //Constructor
	void addEdge(int v, int w);
	void dfs();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); //Add w to v's list
}

void Graph::dfs_util(int v, bool visited[])
{
	visited[v] = true;
	cout << v << " ";

	list<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); ++i)
	{
		if(!visited[*i])
		{
			dfs_util(*i, visited);
		}
	}
}

void Graph::dfs()
{
	bool *visited = new bool[V];
	for(int i = 0; i < V; i++)
	{
		visited[i] = false;
	}
	for(int i = 0; i < V; i++)
	{
		if(visited[i] == false)
		{
			dfs_util(i, visited);
		}
	}
}

int main()
{
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);

	g.dfs();

	return 0;
}