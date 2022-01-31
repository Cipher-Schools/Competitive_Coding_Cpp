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

int largestSumSubtree(TreeNode * root, int &resSoFar) {
    if (root == NULL) {
        return 0;
    } 
    int l = largestSumSubtree(root->left, resSoFar);
    int r = largestSumSubtree(root->right, resSoFar);

    int curr = (root->val + l + r); 
    resSoFar = max(resSoFar, curr);
    return curr;
}

int largestSumSubtree(TreeNode * root) {
    int resSoFar = INT_MIN;
    int res = largestSumSubtree(root, resSoFar);
    return resSoFar;
}