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
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
        }
    }

    vector<vector<int>> levelOrderBottomIterative(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }

        int level = maxDepth(root);
        vector<vector<int>> traversal(level);
        queue<TreeNode *> Q;
        Q.push(root);
        Q.push(NULL);
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
                level--;
            }
            else
            {
                traversal[level - 1].push_back(root->val);

                if (root->left != NULL)
                {
                    Q.push(root->left);
                }

                if (root->right != NULL)
                {
                    Q.push(root->right);
                }
            }
        }
        return traversal;
    }

    void findGivenLevel(TreeNode *root, int level, vector<int> &levelTraversal)
    {
        if (root == NULL)
            return;
        if (level == 1)
        {
            levelTraversal.push_back(root->val);
        }
        else if (level > 1)
        {
            findGivenLevel(root->left, level - 1, levelTraversal);
            findGivenLevel(root->right, level - 1, levelTraversal);
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        int height = maxDepth(root);
        vector<vector<int>> traversal;
        for (int h = height; h >= 1; h--)
        {
            vector<int> hthLevel;
            findGivenLevel(root, h, hthLevel);
            traversal.push_back(hthLevel);
        }
        return traversal;
    }
};