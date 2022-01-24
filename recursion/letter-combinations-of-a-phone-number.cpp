// https://leetcode.com/problems/letter-combinations-of-a-phone-number
#include <bits/stdc++.h>
using namespace std;

vector<string> dialpad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
class Solution
{
public:
     void letterCombinations(string &digits, string &combinationSoFar, int start, int end, vector<string> &combinations)
     {
          if (start > end)
          {
               string dup = combinationSoFar;
               combinations.push_back(dup);
          }
          else
          {
               string possible = dialpad[digits[start] - '0'];
               for (int i = 0; i < possible.size(); i++)
               {
                    combinationSoFar = combinationSoFar + possible[i];
                    letterCombinations(digits, combinationSoFar, start + 1, end, combinations);
                    combinationSoFar = combinationSoFar.substr(0, combinationSoFar.size() - 1);
               }
          }
     }
     vector<string> letterCombinations(string digits)
     {
          if (digits == "")
          {
               return {};
          }
          vector<string> combinations;
          string strSoFAr = "";
          letterCombinations(digits, strSoFAr, 0, digits.length() - 1, combinations);
          return combinations;
     }
};

int main()
{
}
