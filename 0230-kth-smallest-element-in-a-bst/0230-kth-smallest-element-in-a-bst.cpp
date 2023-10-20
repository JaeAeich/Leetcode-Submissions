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
    int c;
    int ans = -1;
    
    void helper(TreeNode* root){
        if(!root) return;
        helper(root->left);
        c--;
        if(c==0) ans = root->val;
        helper(root->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        c = k;
        helper(root);
        return ans;
    }
};