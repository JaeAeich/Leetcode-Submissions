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
    void helper(TreeNode* &root){
        if(!root || (!root->left && !root->right)) return;
        
        TreeNode *left = nullptr; 
        TreeNode *right = nullptr; 
        
        if(root->left) left = root->left;
        if(root->right) right = root->right;
        
        root->left = right;
        root->right = left;
        helper(root->left);
        helper(root->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};