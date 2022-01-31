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

TreeNode * LCA(TreeNode * root, TreeNode *a, TreeNode * b) {
    if (root == NULL) 
        return NULL;
    if (root == a || root == b) {
        return root;
    }
    TreeNode *l = LCA(root->left, a, b);
    TreeNode *r = LCA(root->right, a, b);
    if (l != NULL && r != NULL) {
        // This is our least commmon ancestor
        return root;
    } else {
        return (l != NULL? l : r);
    }
}

void verticalTraversal(TreeNode * root, int level, map<int, vector<int>>& levelNodes) {
    if (root == NULL) {
        return;
    }
    levelNodes[level].push_back(root->val);
    verticalTraversal(root->left, level - 1, levelNodes);
    verticalTraversal(root->right, level + 1, levelNodes);
}

void verticalTraversal(TreeNode *root) {
    map<int, vector<int>> levelNodes;
    verticalTraversal(root, 0, levelNodes);
    for (auto itr = levelNodes.begin(); itr != levelNodes.end(); itr++) {
        for (int i = 0; i < itr->second.size(); i++) {
            cout << itr->second[i] << " ";
        }
        cout << "\n";
    }
}

// find the vertical level wise sum of a binary tree?
