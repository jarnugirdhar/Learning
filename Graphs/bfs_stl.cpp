#include <bits/stdc++.h>
#define pb push_back
#define qi queue<int>
#define vb vector<bool>
#define vi vector<int>

using namespace std;

vb v;
vector<vi> g;

void edge(int a, int b)
{
	g[a].pb(b);
	g[b].pb(a);
}

void bfs(int u)
{
	qi q;
	q.push(u);
	v[u] = true;
	while(!q.empty())
	{
		int f = q.front();
		q.pop();
		cout << f << " ";
		for(auto i = g[f].begin(); i != g[f].end(); ++i)
		{
			if(!v[*i])
			{
				q.push(*i);
				v[*i] = true;
			}
		}
	}
}

int main() 
{ 
    int n, e; 
    cin >> n >> e; 
  
    v.assign(n, false); 
    g.assign(n, vector<int>()); 
  
    int a, b; 
    for (int i = 0; i < e; i++) { 
        cin >> a >> b; 
        edge(a, b); 
    } 
  
    for (int i = 0; i < n; i++) { 
        if (!v[i]) 
            bfs(i); 
    } 
  
    return 0; 
}