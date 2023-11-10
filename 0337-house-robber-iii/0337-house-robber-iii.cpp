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

#include <unordered_map>

class Solution {
private:
    unordered_map<bool, unordered_map<TreeNode*, int>> memo;

    int helper(TreeNode* root, bool pick) {
        if (!root) return 0;

        // Check if the result is already memoized
        if (memo.find(pick) != memo.end() && memo[pick].find(root) != memo[pick].end()) {
            return memo[pick][root];
        }

        int take = 0;

        if (!pick) {
            take = root->val + helper(root->left, true) + helper(root->right, true);
        }

        int leave = helper(root->left, false) + helper(root->right, false);

        // Memoize the result
        memo[pick][root] = max(take, leave);

        return memo[pick][root]; // Corrected this line
    }

public:
    int rob(TreeNode* root) {
        return helper(root, false);
    }
};

