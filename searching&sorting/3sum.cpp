// https://leetcode.com/problems/3sum/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (nums.size() <= 2)
        {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> vec;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int curr1 = nums[i], start = i + 1, end = nums.size() - 1;
            while (start < end)
            {
                int mid = start + (end - start) / 2;
                if (curr1 + nums[start] + nums[end] == 0)
                {
                    vec.push_back({curr1, nums[start], nums[end]});
                    start++;
                    end--;

                    // Now to remove the duplicates in answer, skip the duplicates from the front and the back fo the array segment.
                    while (start < end && nums[start] == nums[start - 1])
                    {
                        start++;
                    }

                    while (start < end && nums[end] == nums[end + 1])
                    {
                        end--;
                    }
                }
                else if (curr1 + nums[start] + nums[end] > 0)
                {
                    end--;
                }
                else
                {
                    start++;
                }
            }
            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
            {
                i++;
            }
        }
        return vec;
    }
};

int main()
{
}