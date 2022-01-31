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

int maxSum = INT_MIN;
void sumRootToLeaf(TreeNode * root, int data) {
    if (root == NULL) {
        return;
    }
    data += root->val;
    if (isLeaf(root)) {
        maxSum = max(maxSum, data);
        cout << "\n";
    } else {
        sumRootToLeaf(root->left, data);
        sumRootToLeaf(root->right, data);
    }
}