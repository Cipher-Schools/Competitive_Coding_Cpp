#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> maxPerWindow;
        deque<int> dq; 
        for (int i = 0; i < nums.size(); i++)
        {
            while (!dq.empty() && i - dq.front() >= k)
                dq.pop_front();

            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);

            if (i >= k - 1)
                maxPerWindow.push_back(nums[dq.front()]);
        }
        return maxPerWindow;
    }
};

int main()
{
}