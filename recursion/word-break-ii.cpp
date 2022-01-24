// https://leetcode.com/problems/word-break-ii
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
     vector<string> wordBreak(string s, vector<string> &wordDict)
     {
          set<string> sortedDict(wordDict.begin(), wordDict.end());
          vector<bool> dp(s.size() + 1);
          vector<vector<string>> dpStr(s.size() + 1);
          dp[0] = true;
          dpStr[0].push_back("");
          for (int i = 1; i <= s.size(); ++i)
          {
               for (int j = 0; j < i; j++)
               {
                    if (dp[j] && sortedDict.find(s.substr(j, i - j)) != sortedDict.end())
                    {
                         dp[i] = true;
                         string suffix = s.substr(j, i - j);
                         for (int k = 0; k < dpStr[j].size(); k++)
                         {
                              if (dpStr[j][k] == "")
                                   dpStr[i].push_back(suffix);
                              else
                                   dpStr[i].push_back(dpStr[j][k] + " " + suffix);
                         }
                    }
               }
          }
          return dpStr[s.size()];
     }
};

int main()
{
}
