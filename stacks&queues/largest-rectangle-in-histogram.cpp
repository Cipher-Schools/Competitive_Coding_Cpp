#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void printArray(vector<int> &heights)
    {
        for (int i = 0; i < heights.size(); i++)
        {
            cout << heights[i] << ", ";
        }
        cout << "\n";
    }
    vector<int> nextSmallerToTheLeft(vector<int> &heights)
    {
        int len = heights.size();
        vector<int> nsl(len);
        stack<int> S;

        for (int i = 0; i < len; i++)
        {
            while (!S.empty() && heights[S.top()] >= heights[i])
            {
                S.pop();
            }
            nsl[i] = (S.empty() ? -1 : S.top());
            S.push(i);
        }
        return nsl;
    }
    vector<int> nextSmallerToTheRight(vector<int> heights)
    {
        int len = heights.size();
        vector<int> nsr(len);
        stack<int> S;

        for (int i = len - 1; i >= 0; i--)
        {
            while (!S.empty() && heights[S.top()] >= heights[i])
            {
                S.pop();
            }
            nsr[i] = (S.empty() ? len : S.top());
            S.push(i);
        }
        return nsr;
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {

        vector<int> left = nextSmallerToTheLeft(heights), right = nextSmallerToTheRight(heights);
        printArray(left);
        printArray(right);

        int maxAr = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            int width = (right[i] - 1) - (left[i] + 1) + 1;
            maxAr = max(maxAr, width * heights[i]);
        }
        return maxAr;
    }
};

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> S;
        heights.push_back(0);
        int result = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            while (S.size() > 0 && heights[S.top()] >= heights[i])
            {
                int y = heights[S.top()];
                S.pop();

                int x = (i - (S.size() > 0 ? S.top() : -1) - 1);
                if (y * x > result)
                    result = y * x;
            }
            S.push(i);
        }

        return result;
    }
};