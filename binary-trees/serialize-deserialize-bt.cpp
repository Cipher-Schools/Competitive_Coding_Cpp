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
class Codec {
public:

    void serialize(TreeNode *root, string &resultSoFar)
     {
          if (root == NULL)
          {
               resultSoFar += "N,";
               return;
          }

          resultSoFar = (resultSoFar + to_string(root->val) + ",");
          serialize(root->left, resultSoFar);
          serialize(root->right, resultSoFar);
     }
     // Encodes a tree to a single string.
     string serialize(TreeNode *root)
     {
          string resultSoFar = "";
          serialize(root, resultSoFar);
          return resultSoFar;
     }

     vector<string> split(const string &s, char delimiter)
     {
          vector<string> splits;
          string split;
          istringstream ss(s);
          while (getline(ss, split, delimiter))
          {
               splits.push_back(split);
          }
          return splits;
     }
     // Decodes your encoded data to tree.
     TreeNode *deserialize(vector<string> &tokens, int &index)
     {
          if (index >= tokens.size())
          {
               return NULL;
          }
          else
          {
               string token = tokens[index];
               index++;
               if (token == "N")
               {
                    return NULL;
               }
               else
               {
                    TreeNode *node = new TreeNode(stoi(token));
                    node->left = deserialize(tokens, index);
                    node->right = deserialize(tokens, index);
                    return node;
               }
          }
     }

     TreeNode *deserialize(string data)
     {
          vector<string> results = split(data, ',');
          int index = 0;
          return deserialize(results, index);
     }
};