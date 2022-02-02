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

TreeNode * sortedArrayToBst(vector<int> vec, int start, int end) {
    if (end < start) {  
        return NULL;
    }
    if (start == end) {
        return new TreeNode(vec[start]);
    }
    
    int mid = start + (end - start)/2;
    TreeNode * newNode = new TreeNode(vec[mid]);
    newNode->left = sortedArrayToBst(vec, start, mid - 1);
    newNode->right = sortedArrayToBst(vec, mid + 1, end);
    return newNode; 
}