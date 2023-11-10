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
    unordered_map<TreeNode*, int> dp;
    
    int helper(TreeNode* root){
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;
        
        if(dp.find(root) != dp.end()) return dp[root];
        
        int pick = root->val;
        if(root->left) pick += helper(root->left->left) + helper(root->left->right);
        if(root->right) pick += helper(root->right->left) + helper(root->right->right);
        
        int leave = helper(root->left) + helper(root->right);
        
        return dp[root] = max(pick, leave);
    }
public:
    int rob(TreeNode* root) {
        int pick = helper(root);
        int leave = 0;
        if(root->left) leave += helper(root->left);
        if(root->right) leave += helper(root->right);
        
        return max(pick, leave);
    }
};