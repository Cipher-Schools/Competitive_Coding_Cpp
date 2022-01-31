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

bool isMirror(TreeNode * a, TreeNode * b) {
    if (a == NULL && b == NULL) return true;
    if (a == NULL || b == NULL) return false;

    if (a->val == b->val) {
        return isMirror(a->left, b->right) && isMirror(a->right, b->left);
    } else {
        return false;
    }
}

bool isMiror(TreeNode * root) {
    return isMirror(root->left, root->right);
}