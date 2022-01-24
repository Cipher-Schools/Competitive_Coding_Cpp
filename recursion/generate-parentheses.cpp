// https://leetcode.com/problems/permutations/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generateParenthesis(string &combinationSoFar, int open, int close, vector<string> &result)
     {
          if (open < 0 || close < 0)
          {
               return;
          }
          else if (open == 0 && close == 0)
          {
               // base case
               string temp = combinationSoFar;
               result.push_back(temp);
          }
          else if (open <= close)
          {
               combinationSoFar += "(";
               generateParenthesis(combinationSoFar, open - 1, close, result);
               combinationSoFar = combinationSoFar.substr(0, combinationSoFar.size() - 1);

               combinationSoFar += ")";
               generateParenthesis(combinationSoFar, open, close - 1, result);
               combinationSoFar = combinationSoFar.substr(0, combinationSoFar.size() - 1);
          }
     }
     vector<string> generateParenthesis(int n)
     {
          vector<string> result = {};
          string combinationSoFar = "";
          generateParenthesis(combinationSoFar, n, n, result);
          return result;
     }
};

int main()
{
}
