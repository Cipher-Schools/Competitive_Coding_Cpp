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

bool isLeaf(TreeNode * root) {
    return (root->left == NULL && root->right == NULL);
}

int leafToleafMaxSum(TreeNode *root, int* sum) {
    if (root == NULL) {
        *sum = 0;
        return 0;
    }
    if (isLeaf(root)) {
        *sum = 0;
        return root->val;
    }

    int leftSum = 0, rightSum = 0;
    leftSum = leafToleafMaxSum(root->left, sum);
    rightSum = leafToleafMaxSum(root->right, sum);
    if (root->left != NULL && root->right != NULL) {
        // Case when both left and right chilren exist
        *sum = max(*sum, leftSum + rightSum + root->val); 
        return max(leftSum, rightSum) + root->val;
    } else if (root->left != NULL) {
        return root->val + rightSum;
    } else {
        // case when root->left == NULL  
        // root->right may or may not be NULL.
        return root->val + leftSum;

    }
}