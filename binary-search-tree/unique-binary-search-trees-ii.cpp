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
    void fixNumbering(TreeNode *root, int &counter)
    {
        if (root != NULL)
        {
            fixNumbering(root->left, counter);
            root->val = counter;
            counter++;
            fixNumbering(root->right, counter);
        }
    }
    TreeNode *createDuplicate(TreeNode *root)
    {
        if (root != NULL)
        {
            TreeNode *copy = new TreeNode(root->val);
            copy->left = createDuplicate(root->left);
            copy->right = createDuplicate(root->right);
            return copy;
        }
        else
        {
            return NULL;
        }
    }
    vector<TreeNode *> generateTrees(int n)
    {
        map<int, vector<TreeNode *>> bsts;
        bsts[0].push_back(NULL);
        bsts[1].push_back({new TreeNode(1)});

        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                int l = (j - 1);
                int r = (i - j);

                for (int ltr = 0; ltr < bsts[l].size(); ltr++)
                {
                    for (int rtr = 0; rtr < bsts[r].size(); rtr++)
                    {
                        TreeNode *newNode = new TreeNode(j);
                        newNode->left = createDuplicate(bsts[l][ltr]);
                        newNode->right = createDuplicate(bsts[r][rtr]);
                        bsts[i].push_back(newNode);
                    }
                }
            }
        }

        for (int i = 0; i < bsts[n].size(); i++)
        {
            int counter = 1;
            fixNumbering(bsts[n][i], counter);
        }
        return bsts[n];
    }
};