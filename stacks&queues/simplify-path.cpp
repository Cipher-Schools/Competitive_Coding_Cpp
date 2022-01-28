#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        path += "/";
        vector<string> result;
        string strSoFar = "";
        for (int i = 0; i < path.length(); i++)
        {
            if (path[i] == '/')
            {
                if (strSoFar != "")
                {
                    if (strSoFar == ".")
                    {
                        // Don't need to do anything. Just ignore it.
                    }
                    else if (strSoFar == "..")
                    {
                        if (result.size() > 0)
                            result.pop_back();
                    }
                    else
                    {
                        result.push_back(strSoFar);
                    }
                    strSoFar = "";
                }
            }
            else
            {
                strSoFar += path[i];
            }
        }

        if (result.size() > 0)
        {
            string simplifiedPath = "";
            for (int i = 0; i < result.size(); i++)
            {
                simplifiedPath += ("/" + result[i]);
            }
            return simplifiedPath;
        }
        else
        {
            return "/";
        }
    }
};

int main()
{
}