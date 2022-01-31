#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right, TreeNode *next) : val(x), left(left), right(right), next(next) {}
};

class Solution
{
public:
    TreeNode *connect(TreeNode *root)
    {
        if (root == NULL)
        {
            return root;
        }

        queue<TreeNode *> Q;
        Q.push(root);
        Q.push(NULL);
        TreeNode *curr, *next = NULL;
        while (!Q.empty())
        {
            curr = Q.front();
            Q.pop();
            if (curr == NULL)
            {
                if (!Q.empty())
                {
                    Q.push(NULL);
                }
                next = NULL;
            }
            else
            {
                curr->next = next;
                next = curr;

                if (curr->right != NULL)
                {
                    Q.push(curr->right);
                }

                if (curr->left != NULL)
                {
                    Q.push(curr->left);
                }
            }
        }
        return root;
    }
};