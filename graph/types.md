### Types of Graph
1. Undirected Graphs / Directed Graphs
2. Weighted Graphs / Unweighted Graphs
3. Special
    3.a Trees
    3.b Directed Acyclic Graphs (Scheduler, Compiler, Dependency System, etc.)
    3.c Bipartite Graph (m-color problem)
    3.d Complete Graph

### Graph Representation
1. Adjacency Matrix
2. Adjacency List

Common problems in Graph
1. Shorted Path Problem: Given a weighted graph, find the shorted path of edges from node A to node B.
    BFS(Unweighted Graph)
    Dijkstra's, Bellman Ford, FLoyd Warshall, A* (General)

2. Connectivity: Does there exists a path from Node A to Node B
    Union Path Algorithm
    Basic Traversal (DFS, BFS)

3.  Detecting Negative Cycles in a Graph
    Bellman Ford, Floyd Warshall Algorithms

4. Strongly Connected Components: can be thought of as self-contained cycles within a directed graph 
   where each vertex in the given cycle can reach every other vertex in the same cycle.
   Tarzan, Kosaraju

5. Travelling Salesman problem: Given a list of cities and the distance between each pair of cities, 
   what is the shortest possible route that visits each city exactly once and returns to the origin city?
   NP-Hard Problem, Approximations only
   Branch and Bound, Held-Karp, etc.

6. Bridges/Articulation Points - A bridge or cut edge is any edge in the graph whose removal increases the number of connected components. 
                               - Articulation point is an edge in the graph whose removal increases the number of connected components. 
   Bottlenexts, vulnerabilities, 

7. Minimum Spanning Tree - A MST is an subset of the edges of a connected, edge-weighted graph that connects all the vertices together, 
   without any cycles and with minimum total possible edge weight.
   Prim's,  Kruskal's, 

8. Networ Flow. With infinite input source, how much flow can we push through the network? Edge weights represent capacity.
Ford Fulkersons, Edmonds-Karp & Dini's algorithms.
