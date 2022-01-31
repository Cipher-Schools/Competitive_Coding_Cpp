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

void printAllPaths(TreeNode * root, vector<int>& path) {
    if (root == NULL) {
        return;
    }
    path.push_back(root->val);
    if (isLeaf(root)) {
        for (int i = 0; i <path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << "\n";
    } else {
        printAllPaths(root->left, path);
        printAllPaths(root->right, path);
    }
    // backtracking step
    path.pop_back();
}