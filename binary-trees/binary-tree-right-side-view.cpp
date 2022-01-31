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
    vector<int> rightSideView(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }

        vector<int> traversal;
        queue<TreeNode *> Q;
        Q.push(root);
        Q.push(NULL);
        bool isFirst = true;
        while (!Q.empty())
        {
            root = Q.front();
            Q.pop();
            if (root == NULL)
            {
                if (!Q.empty())
                {
                    Q.push(NULL);
                }
                isFirst = true;
            }
            else
            {
                if (isFirst)
                {
                    traversal.push_back(root->val);
                    isFirst = false;
                }

                if (root->right != NULL)
                {
                    Q.push(root->right);
                }

                if (root->left != NULL)
                {
                    Q.push(root->left);
                }
            }
        }
        return traversal;
    }
};