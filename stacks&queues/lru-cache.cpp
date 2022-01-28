#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> order;
    int size;
    int capacity;

public:
    LRUCache(int capacity)
    {
        this->size = 0;
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
        {
            // Page Miss
            return -1;
        }
        else
        {
            // Page Hit
            this->order.erase(this->cache[key].second);
            this->order.push_front(key);
            this->cache[key].second = this->order.begin();
            return this->cache[key].first;
        }
    }

    void put(int key, int value)
    {
        if (this->cache.find(key) == this->cache.end())
        {
            // Page Miss -. Not present
            this->order.push_front(key);
            this->cache[key] = {value, this->order.begin()};
            this->size++;
        }
        else
        {
            // Page Hit
            this->cache[key].first = value;
            this->order.erase(this->cache[key].second);
            this->order.push_front(key);
            this->cache[key].second = this->order.begin();
        }

        if (this->size > this->capacity)
        {
            this->cache.erase(this->order.back());
            this->order.pop_back();
            this->size--;
        }
    }
};

class LRUCache1
{
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> order;
    int size;
    int capacity;

public:
    LRUCache1(int capacity)
    {
        this->size = 0;
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
        {
            // Page Miss
            return -1;
        }
        else
        {
            // Page Hit
            this->order.splice(this->order.begin(), this->order, this->cache[key].second);
            this->cache[key].second = this->order.begin();
            return this->cache[key].first;
        }
    }

    void put(int key, int value)
    {
        if (this->cache.find(key) == this->cache.end())
        {
            // Page Miss -. Not present
            this->order.push_front(key);
            this->cache[key] = {value, this->order.begin()};
            this->size++;
        }
        else
        {
            // Page Hit
            this->cache[key].first = value;
            this->order.splice(this->order.begin(), this->order, this->cache[key].second);
            this->cache[key].second = this->order.begin();
        }

        if (this->size > this->capacity)
        {
            this->cache.erase(this->order.back());
            this->order.pop_back();
            this->size--;
        }
    }
};

int main()
{
}