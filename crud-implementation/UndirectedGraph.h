#include <bits/stdc++.h>
using namespace std;

class UndirectedGraph
{
  private:
    int V;
    list<int> *adj;

    bool IsCyclicHelper(int source, int parent, vector<bool> &visited);

  public:
    UndirectedGraph(int V);

    void AddEdge(int source, int destination);

    void RemoveEdge(int source, int destination);

    bool IsCyclic();
};

UndirectedGraph::UndirectedGraph(int V)
{
    this->V = V;
    adj = new list<int>[this->V];
}

void UndirectedGraph::AddEdge(int source, int destination)
{
    if (source >= this->V || destination >= this->V)
    {
        throw "No such nodes exist!!";
    }
    this->adj[source].push_back(destination);
    this->adj[destination].push_back(source);
}

void UndirectedGraph::RemoveEdge(int source, int destination)
{
    if (source >= this->V || destination >= this->V)
    {
        throw "No such nodes exist!!";
    }

    this->adj[source].erase(find(this->adj[source].begin(), this->adj[source].begin(), destination));
    this->adj[destination].erase(find(this->adj[destination].begin(), this->adj[destination].begin(), source));
}

bool UndirectedGraph::IsCyclicHelper(int source, int parent, vector<bool> &visited)
{
    visited[source] = true;
    for (auto itr = this->adj[source].begin(); itr != this->adj[source].end(); itr++)
    {
        if (!visited[*itr])
        {
            if (IsCyclicHelper(*itr, source, visited))
                return true;
        }
        else
        {
            if (*itr != parent)
                return true;
        }
    }

    return false;
}

bool UndirectedGraph::IsCyclic()
{
    vector<bool> visited(this->V, false);

    for (int i = 0; i < this->V; i++)
    {
        if (!visited[i])
        {
            if (IsCyclicHelper(i, -1, visited))
                return true;
        }
    }
    return false;
}