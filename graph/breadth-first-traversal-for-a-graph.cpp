#include <iostream>
#include <list>
using namespace std;

class graph
{
	private:
		list<int>* adj;
		int V;
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
		void BFS(int s);
		//void DFS(int s);
};

void graph::BFS(int s){
	bool* visited = new bool[V];
	for (int i = 0; i < V; ++i)
	{
		visited[i] = false;
	}
	list<int> Q;
	Q.push_back(s);
	visited[s] = true;
	list<int>::iterator itr;
	while(Q.empty()==false)
	{
		s = Q.front();
		Q.pop_front();
		cout<<s<<" ";
		for(itr = adj[s].begin();itr != adj[s].end();itr++)
		{
			if(visited[*itr] == false)
			{
				visited[*itr] = true;
				Q.push_back(*itr);
			}
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
    g.BFS(2);
	return 0;
}