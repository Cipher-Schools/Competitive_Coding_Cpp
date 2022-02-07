#include <bits/stdc++.h>
using namespace std;

// Naive Implementation
class DisjointSet
{
    int *parent;
    int N;

public:
    DisjointSet(int N)
    {
        this->N = N;
        this->parent = new int[this->N];
        for (int i = 0; i < N; i++)
            this->parent[i] = i;
    }

    //returns true,if A and B are connected, else it will return false.
    bool Find(int A, int B)
    {
        return (this->parent[A] == this->parent[B]);
    }

    void Union(int A, int B)
    {
        int temp = this->parent[A];
        for (int i = 0; i < this->N; i++)
        {
            if (this->parent[i] == temp)
                this->parent[i] = this->parent[B];
        }
    }
};

class OptimizedDisjointSet
{
    int *parent, *_size;
    int N;

public:
    OptimizedDisjointSet(int N)
    {
        this->N = N;
        parent = new int[this->N + 1];
        _size = new int[this->N + 1];
        for (int i = 1; i <= N; i++)
        {
            parent[i] = i;
            _size[i] = 1;
        }
    }

    void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);

        if (_size[a] > _size[b])
            swap(a, b);

        if (a != b)
        {
            parent[a] = b;
            _size[b] += _size[a];
        }
    }

    int Find(int a)
    {
        if (a != parent[a])
            parent[a] = Find(parent[a]);
        return parent[a];
    }
};
