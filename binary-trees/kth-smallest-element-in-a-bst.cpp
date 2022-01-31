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
    void kthSmallest(TreeNode *root, int &k, bool &found, int &result)
    {
        if (root == NULL)
            return;
        if (found)
            return;
        kthSmallest(root->left, k, found, result);
        k--;
        if (k == 0)
        {
            result = root->val;
            found = true;
            return;
        }
        kthSmallest(root->right, k, found, result);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        int result;
        bool found = false;
        kthSmallest(root, k, found, result);
        return result;
    }
};