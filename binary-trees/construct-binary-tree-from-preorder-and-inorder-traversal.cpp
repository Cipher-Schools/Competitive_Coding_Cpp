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
    int find(vector<int> &inorder, int start, int end, int target)
    {
        for (int i = start; i <= end; i++)
        {
            if (inorder[i] == target)
            {
                return i;
            }
        }
        return -1;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int start, int end, int &preIndex)
    {
        if (start > end)
        {
            return NULL;
        }
        TreeNode *newNode = new TreeNode(preorder[preIndex]);
        preIndex++;
        if (start == end)
        {
            return newNode;
        }
        else
        {
            int inIndex = find(inorder, start, end, newNode->val);
            newNode->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
            newNode->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);
            return newNode;
        }
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int start = 0, end = preorder.size() - 1, preIndex = 0;
        return buildTree(preorder, inorder, start, end, preIndex);
    }
};