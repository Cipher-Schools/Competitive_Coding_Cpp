// https://leetcode.com/problems/course-schedule-ii/
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int dest;
    double weight;
    Node(int dest)
    {
        this->dest = dest;
        this->weight = 1.0;
    }
    Node(int dest, double weight)
    {
        this->dest = dest;
        this->weight = weight;
    }

    operator string() const { return this->dest + ", " + to_string(this->weight); }
};
class Graph
{
    bool topologicalSort(int source, vector<bool> &visited, vector<bool> &pathSoFar, stack<int> &dfsTraversal)
    {
        visited[source] = true;
        pathSoFar[source] = true;
        for (auto itr = this->adj[source].begin(); itr != this->adj[source].end(); ++itr)
        {
            if (!visited[(*itr)->dest] && topologicalSort((*itr)->dest, visited, pathSoFar, dfsTraversal))
            {
                return true;
            }
            else if (pathSoFar[(*itr)->dest])
            {
                return true;
            }
        }
        pathSoFar[source] = false;
        dfsTraversal.push(source);
        return false;
    }

public:
    int V;
    list<Node *> *adj;
    Graph(int V)
    {
        this->V = V;
        this->adj = new list<Node *>[this->V];
    }

    void AddEdge(int u, int v, double w = 1.0)
    {
        Node *newNode = new Node(v, w);
        this->adj[u].push_back(newNode);
    }

    vector<int> TopologicalSort()
    {
        vector<bool> visited(this->V, false);
        vector<bool> path(this->V, false);
        stack<int> dfsTraversal;
        vector<int> ts;
        for (int v = 0; v < this->V; v++)
        {
            if (!visited[v] && topologicalSort(v, visited, path, dfsTraversal))
            {
                return {};
            }
        }

        while (!dfsTraversal.empty())
        {
            ts.push_back(dfsTraversal.top());
            dfsTraversal.pop();
        }
        return ts;
    }
};

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        Graph g(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            g.AddEdge(prerequisites[i][1], prerequisites[i][0]);
        }
        vector<int> result = g.TopologicalSort();
        return result;
    }
};