// https://leetcode.com/problems/search-in-rotated-sorted-array/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int start, int end, int target)
     {
          if (start > end)
          {
               return -1;
          }
          int mid = start + (end - start) / 2;
          if (nums[mid] == target)
          {
               return mid;
          }

          if (nums[start] <= nums[mid])
          {
               // first segment sorted
               if (nums[start] <= target && target < nums[mid])
               {
                    return search(nums, start, mid - 1, target);
               }
               else
               {
                    return search(nums, mid + 1, end, target);
               }
          }
          else
          {
               // second segment sorted
               if (nums[mid] < target && target <= nums[end])
               {
                    return search(nums, mid + 1, end, target);
               }
               else
               {
                    return search(nums, start, mid - 1, target);
               }
          }
     }

     int search(vector<int> &nums, int target)
     {
          return search(nums, 0, nums.size() - 1, target);
     }
};