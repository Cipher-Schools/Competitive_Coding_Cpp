#include <bits/stdc++.h>
using namespace std;

// Directed Graph
class DirectedGraph
{
    int V;
    list<int> *adj;

    void DepthFirstTraversalHelper(int source, vector<bool> &visited)
    {
        cout << source << ' ';
        visited[source] = true;
        for (auto itr = adj[source].begin(); itr != adj[source].end(); itr++)
        {
            if (!visited[*itr])
            {
                DepthFirstTraversalHelper(*itr, visited);
            }
        }
    }

    void BreadthFirstTraversalHelper(int source, vector<bool> &visited, queue<int> Q)
    {
        int temp;
        while (!Q.empty())
        {
            temp = Q.front();
            Q.pop();
            cout << temp << ' ';
            for (auto itr = adj[temp].begin(); itr != adj[temp].end(); itr++)
            {
                if (!visited[*itr])
                {
                    Q.push(*itr);
                    visited[*itr] = true;
                }
            }
        }
    }

    bool IsCyclicHelper(int source, vector<bool> &visited, vector<bool> &recStack)
    {
        if (!visited[source])
        {
            visited[source] = true;
            recStack[source] = true;

            for (auto itr = adj[source].begin(); itr != adj[source].end(); itr++)
            {
                if (!visited[*itr] && IsCyclicHelper(*itr, visited, recStack))
                    return true;
                else if (recStack[*itr])
                    return true;
            }

            recStack[source] = false;
            return false;
        }
    }

    void TopologicalSortHelper(int source, vector<bool> &visited, stack<int> &S)
    {
        visited[source] = true;

        for (auto itr = adj[source].begin(); itr != adj[source].end(); itr++)
        {
            if (!visited[*itr])
            {
                TopologicalSortHelper(*itr, visited, S);
            }
        }
        S.push(source);
    }

  public:
    DirectedGraph(int V)
    {
        this->V = V;
        adj = new list<int>[this->V];
    }

    void AddEdge(int u, int v)
    {
        if (u >= this->V || v >= this->V)
        {
            throw "No such nodes exist!!";
        }
        else
        {
            adj[u].push_back(v);
        }
    }

    void AddEdge(const vector<pair<int, int>> edges)
    {
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i].first].push_back(edges[i].second);
        }
    }

    void RemoveEdge(int u, int v)
    {
        if (u >= this->V || v >= this->V)
        {
            throw "No such node exist!!";
        }

        list<int>::iterator itr = find(adj[u].begin(), adj[u].end(), v);
        if (itr != adj[u].end())
        {
            adj[u].erase(itr);
        }
        else
        {
            throw "Remove Edge: No edge exists between given nodes!!";
        }
    }

    void DepthFirstTraversal()
    {
        vector<bool> visited(this->V, false);

        for (int i = 0; i < this->V; i++)
        {
            if (!visited[i])
            {
                DepthFirstTraversalHelper(i, visited);
            }
        }
        cout << "\n";
    }

    void BreadthFirstTraversal()
    {
        vector<bool> visited(this->V, false);
        queue<int> Q;
        for (int i = 0; i < this->V; i++)
        {
            if (!visited[i])
            {
                Q.push(i);
                visited[i] = true;
                BreadthFirstTraversalHelper(i, visited, Q);
            }
        }
        cout << "\n";
    }

    bool IsCyclic()
    {
        vector<bool> visited(this->V, false);
        vector<bool> recStack(this->V, false);

        for (int i = 0; i < this->V; i++)
        {
            if (IsCyclicHelper(i, visited, recStack))
                return true;
        }

        return false;
    }

    void TopologicalSort()
    {
        if (IsCyclic())
        {
            throw "Graph is cyclic!!";
        }

        vector<bool> visited(this->V, false);
        stack<int> S;

        for (int i = 0; i < this->V; i++)
        {
            if (!visited[i])
            {
                TopologicalSortHelper(i, visited, S);
            }
        }

        while (!S.empty())
        {
            cout << S.top() << " ";
            S.pop();
        }
        cout << "\n";
    }
};