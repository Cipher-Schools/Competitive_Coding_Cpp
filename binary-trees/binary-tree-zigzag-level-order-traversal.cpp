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

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }
        vector<vector<int>> traversal;
        traversal.push_back({});
        stack<TreeNode *> S1, S2;
        S1.push(root);
        int level = 0;
        bool l2r = true;
        while (!S1.empty())
        {
            root = S1.top();
            S1.pop();
            traversal[level].push_back(root->val);
            if (l2r)
            {
                if (root->left != NULL)
                {
                    S2.push(root->left);
                }

                if (root->right != NULL)
                {
                    S2.push(root->right);
                }
            }
            else
            {
                if (root->right != NULL)
                {
                    S2.push(root->right);
                }

                if (root->left != NULL)
                {
                    S2.push(root->left);
                }
            }

            if (S1.empty())
            {
                level++;
                swap(S1, S2);
                if (!S1.empty())
                {
                    traversal.push_back({});
                    l2r = !l2r;
                }
            }
        }
        return traversal;
    }
};