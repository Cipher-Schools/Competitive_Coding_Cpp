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

void leftView(TreeNode * root) {
    if (root == NULL)
        return;
    queue<TreeNode *> Q;
    Q.push(root);
    while (!Q.empty()) {
        int size = Q.size();
        for (int i = 0; i < size; i++) {
            root = Q.front(); Q.pop();
            if (i == 0) {
                cout << root->val << " ";
            }
            
            if (root->left != NULL) {
                Q.push(root->left);
            }

            if (root->right != NULL) {
                Q.push(root->right);
            }
        }
    }
}

void rightView(TreeNode * root) {
    if (root == NULL)
        return;
    queue<TreeNode *> Q;
    Q.push(root);
    while (!Q.empty()) {
        int size = Q.size();
        for (int i = 0; i < size; i++) {
            root = Q.front(); Q.pop();
            if (i == size - 1) {
                cout << root->val << " ";
            }
            
            if (root->left != NULL) {
                Q.push(root->left);
            }

            if (root->right != NULL) {
                Q.push(root->right);
            }
        }
    }
}