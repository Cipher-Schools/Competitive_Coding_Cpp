// https://leetcode.com/problems/all-paths-from-source-to-target
#include <bits/stdc++.h>
using namespace std;

class DirectedGraph
{
    list<int> *adj;
    int V;

public:
    DirectedGraph(int V)
    {
        this->V = V;
        this->adj = new list<int>[this->V];
    }

    void AddEdge(int u, int v, int w = 0)
    {
        this->adj[u].push_back(v);
    }

    vector<vector<int>> AllPaths(int source, int destination)
    {
        vector<vector<int>> paths;
        vector<bool> visited(this->V, false);
        vector<int> path;
        allPaths(source, destination, path, visited, paths);
        return paths;
    }

private:
    void allPaths(int source, int destination, vector<int> &path, vector<bool> &visited, vector<vector<int>> &paths)
    {
        path.push_back(source);
        visited[source] = true;
        if (source == destination)
        {
            paths.push_back(vector<int>(path.begin(), path.end()));
        }
        else
        {
            for (auto itr = this->adj[source].begin(); itr != this->adj[source].end(); itr++)
            {
                if (!visited[*itr])
                {
                    allPaths(*itr, destination, path, visited, paths);
                }
            }
        }

        path.pop_back();
        visited[source] = false;
    }
};

class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        int V = graph.size();
        DirectedGraph dg(V);
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                dg.AddEdge(i, graph[i][j]);
            }
        }

        return dg.AllPaths(0, V - 1);
    }
};