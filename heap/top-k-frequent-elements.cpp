// https://leetcode.com/problems/top-k-frequent-elements
#include <bits/stdc++.h>
using namespace std;

class comparator
{
public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    }
};

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;
        for (auto itr = freq.begin(); itr != freq.end(); itr++)
        {
            if (pq.size() < k)
            {
                pq.push(pair<int, int>(itr->first, itr->second));
            }
            else
            {
                if (pq.top().second < itr->second)
                {
                    pq.pop();
                    pq.push(pair<int, int>(itr->first, itr->second));
                }
            }
        }
        vector<int> result(k);
        int i = 0;
        while (!pq.empty())
        {
            result[i++] = pq.top().first;
            pq.pop();
        }
        return result;
    }
};

int main()
{
}