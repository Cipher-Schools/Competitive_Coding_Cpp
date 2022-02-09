// https://leetcode.com/problems/course-schedule
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

    operator string() const { return to_string(this->dest) + ", " + to_string(this->weight); }
};
class Graph
{
    bool isCyclic(int source, vector<bool> &visited, vector<bool> &pathSoFar)
    {
        visited[source] = true;
        pathSoFar[source] = true;
        for (auto itr = this->adj[source].begin(); itr != this->adj[source].end(); ++itr)
        {
            if (!visited[(*itr)->dest] && isCyclic((*itr)->dest, visited, pathSoFar))
            {
                return true;
            }
            else if (pathSoFar[(*itr)->dest])
            {
                return true;
            }
        }
        pathSoFar[source] = false;
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

    bool isCyclic()
    {
        vector<bool> visited(this->V, false);
        vector<bool> path(this->V, false);
        for (int v = 0; v < this->V; v++)
        {
            if (!visited[v] && isCyclic(v, visited, path))
            {
                return true;
            }
        }
        return false;
    }
};

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        Graph g(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            g.AddEdge(prerequisites[i][1], prerequisites[i][0]);
        }
        return !g.isCyclic();
    }
};