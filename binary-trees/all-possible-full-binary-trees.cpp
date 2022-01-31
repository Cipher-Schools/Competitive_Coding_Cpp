#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *CloneTree(TreeNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        TreeNode *newNode = new TreeNode(root->val);
        newNode->left = CloneTree(root->left);
        newNode->right = CloneTree(root->right);
        return newNode;
    }
}
class Solution
{
public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        if (n & 1 == 0)
            return {};
        else
        {
            vector<vector<TreeNode *>> dp(n + 1);
            dp[0].push_back(NULL);
            dp[1].push_back(new TreeNode(0));
            for (int i = 3; i <= n; i += 2)
            {
                // cout << "-----------------\n";
                for (int leftSize = 1; leftSize < i; leftSize += 2)
                {
                    int rightSize = i - 1 - leftSize;
                    // cout << leftSize << " " << rightSize << endl;
                    for (int j = 0; j < dp[leftSize].size(); j++)
                    {
                        for (int k = 0; k < dp[rightSize].size(); k++)
                        {
                            TreeNode *node = new TreeNode(0);
                            node->left = CloneTree(dp[leftSize][j]);
                            node->right = CloneTree(dp[rightSize][k]);
                            dp[i].push_back(node);
                        }
                    }
                }
            }

            return dp[n];
        }
    }
};