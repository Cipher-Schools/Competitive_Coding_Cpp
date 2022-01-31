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
    unordered_map<int, int> index;
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int start, int end, int &postIndex)
    {
        if (start > end)
            return NULL;
        int inorderIndex = this->index[postorder[postIndex]];

        TreeNode *root = new TreeNode(inorder[inorderIndex]);

        (postIndex)--;
        root->right = buildTree(inorder, postorder, inorderIndex + 1, end, postIndex);
        root->left = buildTree(inorder, postorder, start, inorderIndex - 1, postIndex);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            this->index[inorder[i]] = i;
        }
        int start = 0, end = postorder.size() - 1, postIndex = postorder.size() - 1;
        return buildTree(inorder, postorder, start, end, postIndex);
    }
};