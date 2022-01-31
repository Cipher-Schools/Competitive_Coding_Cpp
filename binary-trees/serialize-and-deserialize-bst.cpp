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

class Codec
{
public:
    void serialize(TreeNode *root, string &data)
    {
        if (root == NULL)
        {
            return;
        }
        data = data + to_string(root->val) + ",";
        serialize(root->left, data);
        serialize(root->right, data);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string data = "";
        serialize(root, data);
        return data;
    }

    TreeNode *deserialize(vector<int> &tokens, int start, int end)
    {
        if (start > end)
            return NULL;
        TreeNode *newNode = new TreeNode(tokens[start]);
        if (start == end)
        {
            return newNode;
        }

        int index = start + 1;
        while (index <= end && tokens[index] < newNode->val)
        {
            index++;
        }
        newNode->left = deserialize(tokens, start + 1, index - 1);
        newNode->right = deserialize(tokens, index, end);
        return newNode;
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        vector<int> tokens;
        string token;
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] == ',')
            {
                tokens.push_back(stoi(token));
                token = "";
            }
            else
            {
                token += data[i];
            }
        }
        return deserialize(tokens, 0, tokens.size() - 1);
    }
};