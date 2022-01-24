// https://leetcode.com/problems/permutations/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void permute(vector<vector<int>> &result, vector<int> &nums, int start, int end)
    {
        if (start > end)
        {
            result.push_back(vector<int>(nums.begin(), nums.end()));
            return;
        }
        else
        {
            for (int i = start; i <= end; i++)
            {
                swap(nums[start], nums[i]);
                permute(result, nums, start + 1, end);
                swap(nums[start], nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        permute(result, nums, 0, nums.size() - 1);
        return result;
    }
};

int main()
{
}
