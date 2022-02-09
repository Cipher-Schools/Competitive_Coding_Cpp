#include <iostream>
#include <list>
using namespace std;

class graph
{
	private:
		list<int>* adj;
		int V;
		void DFSUtil(int s, bool visited[]);
	public:
		graph(int V)
		{
			this->V = V;
			adj  = new list<int>[V];
		}
		void addEdge(int u,int v)
		{
			adj[u].push_back(v);
		}
		//void BFS(int s);
		void DFS();
};

void graph::DFSUtil(int s, bool visited[])
{
	visited[s] = true;
	cout<<s<<" ";
	list<int>:: iterator itr;
	for(itr = adj[s].begin();itr != adj[s].end();itr++)
	{
		if(visited[*itr] == false)
		{
			DFSUtil(*itr,visited);
		}
	}
}

void graph::DFS()
{
	bool* visited = new bool[V];
	for (int i = 0; i < V; ++i)
	{
		visited[i] = false;
	}
	for(int i = 0;i < V;i++){
		if(visited[i]==false){
			DFSUtil(i,visited);
		}
	}
}

int main(){
	graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.DFS();
	return 0;
}