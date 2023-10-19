/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 https://assets.leetcode.com/uploads/2018/12/14/binarytree.png*     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans = nullptr;
    
    bool check(TreeNode* root, TreeNode* p){
        if(!root) return false;
        if(root == p) return true;
        
        return check(root->left, p) || check(root->right, p);
    }
    
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return;
        
        bool pCheck = check(root, p);
        bool qCheck = check(root, q);
        
        if(pCheck and qCheck){
            ans = root;
        }
        
        dfs(root->left, p, q);
        dfs(root->right, p, q);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};