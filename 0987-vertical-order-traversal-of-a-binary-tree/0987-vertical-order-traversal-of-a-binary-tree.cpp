/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    map<int, map<int, multiset<int>>> m;
    queue<pair<TreeNode*, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while (!q.empty()) {
      auto node = q.front().first;
      int vLevel = q.front().second.first;
      int hLevel = q.front().second.second;

      q.pop();
      m[hLevel][vLevel].insert(node->val);
      if (node->left) q.push({node->left, {vLevel + 1, hLevel - 1}});
      if (node->right) q.push({node->right, {vLevel + 1, hLevel + 1}});
    }

    for (auto it = m.begin(); it != m.end(); ++it) {
      vector<int> temp;
      for (auto i = it->second.begin(); i != it->second.end(); ++i) {
        for (auto j = i->second.begin(); j != i->second.end(); ++j) {
          temp.push_back(*j);
        }
      }
      ans.push_back(temp);
    }

    return ans;
  }
};