// https://leetcode.com/problems/maximum-subarray/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int currSum = nums[0];
        int sumSoFar = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            currSum = max(currSum + nums[i], nums[i]);
            sumSoFar = max(sumSoFar, currSum);
        }

        return sumSoFar;
    }
};

int main()
{
}