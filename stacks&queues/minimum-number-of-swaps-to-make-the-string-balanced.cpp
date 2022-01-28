// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwaps(string s)
    {
        string unpurifiedString = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '[')
            {
                unpurifiedString.push_back(s[i]);
            }
            else if (s[i] == ']')
            {
                if (!unpurifiedString.empty() && unpurifiedString.back() == '[')
                {
                    unpurifiedString.pop_back();
                }
                else
                {
                    unpurifiedString.push_back(s[i]);
                }
            }
        }

        return ((unpurifiedString.size() / 2) + 1) / 2;
    }
};

int main()
{
}