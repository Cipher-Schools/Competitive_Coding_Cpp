#include <iostream>
#include <list>
using namespace std;

class Graph
{
private:
	int V;
	list<int>* adj;
	void DFSUtil(int u,bool * visited);
public:
	Graph(int V)
	{
		this->V  = V;
		adj = new list<int>[V];
	}
	void addEdge(int u,int v)
	{
		adj[u].push_back(v);
	}
	void BFS(int s);
	void DFS();
};

void Graph::BFS(int s)
{
	bool * visited = new bool[V];
	for (int i = 0; i < V; ++i)
	{
		visited[i] = false;
	}
	list<int> Q;
	Q.push_back(s);
	visited[s] = true;
	list<int>::iterator itr;
	while(Q.empty() == false)
	{
		s = Q.front();
		Q.pop_front();
		cout<<s<<" ";
		for(itr = adj[s].begin();itr !=adj[s].end(); itr++)
		{
			if(!visited[*itr])
			{
				visited[*itr] = true;
				Q.push_back(*itr);
			}
		}
	}
}

void Graph::DFSUtil(int u,bool * visited)
{
	visited[u] = true;
	cout<<u<<" ";
	list<int>::iterator itr;
	for(itr = adj[u].begin(); itr != adj[u].end(); itr++)
	{
		if(!visited[*itr])
		{
			DFSUtil(*itr, visited);
		}
	}
}

void Graph::DFS()
{
	bool * visited = new bool[V];
	for (int i = 0; i < V; ++i)
	{
		visited[i] = false;
	}
	for (int i = 0; i < V; ++i)
	{
		if(visited[i] == false)
		{
			DFSUtil(i,visited);
		}
	}
}
int main()
{
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
	g.DFS();
	return 0;
}