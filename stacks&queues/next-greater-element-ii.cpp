#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums)
     {
          stack<int> S;
          vector<int> result(nums.size());
          for (int i = nums.size() - 1; i >= 0; i--)
          {
               while (!S.empty() && S.top() <= nums[i])
               {
                     S.pop();
               }
               S.push(nums[i]);
          }
          

          for (int i = nums.size() - 1; i >= 0; i--)
          {
               if (S.empty())
               {
                    result[i] = -1;
               }
               else
               {
                    while (!S.empty() && S.top() <= nums[i])
                    {
                         S.pop();
                    }

                    result[i] = (S.empty() ? -1 : S.top());
               }
              S.push(nums[i]);
          }
          return result;
     }
};

int main() {

}