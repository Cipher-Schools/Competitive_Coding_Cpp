#include <bits/stdc++.h>
using namespace std;

bool comparator(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0];
}
class Solution
{
public:
    bool areOverlapping(const vector<int> &a, const vector<int> &b)
    {
        return (a[1] >= b[0]);
    }

    vector<int> mergeIntervals(vector<int> &a, vector<int> &b)
    {
        return {a[0], max(a[1], b[1])};
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() <= 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), comparator);
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (areOverlapping(merged.back(), intervals[i]))
            {
                vector<int> temp = mergeIntervals(merged.back(), intervals[i]);
                merged.pop_back();
                merged.push_back(temp);
            }
            else
            {
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};