// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstOccurrence(vector<int> &nums, int start, int end, int target)
    {
        if (start > end)
            return -1;
        if (start == end)
        {
            return (target == nums[start] ? start : -1);
        }
        int mid = start + (end - start) / 2;

        if (nums[mid] == target)
        {
            // element found but not sure if this is the first occurrence or not.
            // check if this is the first occurrence of target.
            if ((mid == 0) || (mid - 1 >= 0 && nums[mid] > nums[mid - 1]))
                return mid;
            else
            {
                return firstOccurrence(nums, start, mid - 1, target);
            }
        }
        else if (nums[mid] < target)
        {
            // element lies in the second segment.
            return firstOccurrence(nums, mid + 1, end, target);
        }
        else
        {
            // eleement lies in the first segment.
            return firstOccurrence(nums, start, mid - 1, target);
        }
    }

    int lastOccurrence(vector<int> &nums, int start, int end, int target)
    {
        if (start > end)
            return -1;
        if (start == end)
        {
            return (target == nums[start] ? start : -1);
        }
        int mid = start + (end - start) / 2;

        if (nums[mid] == target)
        {
            // element found but not sure if this is the first occurrence or not.
            // check if this is the first occurrence of target.
            if ((mid == end) || (mid + 1 <= end && nums[mid] < nums[mid + 1]))
                return mid;
            else
            {
                return lastOccurrence(nums, mid + 1, end, target);
            }
        }
        else if (nums[mid] < target)
        {
            // element lies in the second segment.
            return lastOccurrence(nums, mid + 1, end, target);
        }
        else
        {
            // eleement lies in the first segment.
            return lastOccurrence(nums, start, mid - 1, target);
        }
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int first = firstOccurrence(nums, 0, nums.size() - 1, target);
        int last = lastOccurrence(nums, 0, nums.size() - 1, target);
        cout << first << " " << last << "\n";
        return {first, last};
    }
};

int main()
{
}