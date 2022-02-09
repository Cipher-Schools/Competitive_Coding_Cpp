// https://leetcode.com/problems/clone-graph/
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    unordered_map<Node *, Node *> copies;
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;
        
        if (copies.find(node) == copies.end()) {
            copies[node] = new Node(node->val, {});
            for (Node * neighbor : node->neighbors) {
                copies[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return copies[node];
    }
};