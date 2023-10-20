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
private:
    bool helper(TreeNode* root, long long int lo, long long int hi){
        if(!root) return true;
        long long int val = root->val;
        return (val > lo && val < hi) && helper(root->left, lo, val) && helper(root->right, val, hi);
    }
public:
    bool isValidBST(TreeNode* root) {
        long long int lo = LLONG_MIN, hi = LLONG_MAX;
        return helper(root, lo, hi);
    }
};
