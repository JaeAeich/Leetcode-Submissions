/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    TreeNode* ans = nullptr;
    
    bool has(TreeNode* root, TreeNode* p){
        if(!root) return false;
        
        return root == p || has(root->left, p) || has(root->right, p);
        
    }
    
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return ;
        if(has(root, p) && has(root, q)) ans = root;
        dfs(root->left, p, q);
        dfs(root->right, p, q);
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};