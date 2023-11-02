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
    int ans = 0;
    
    void helper(TreeNode* root, bool right, int c){
        if(!root) return;
        ans = max(c, ans);
        if(right){
            helper(root->right, false, c + 1);
            helper(root->left, true, 1);
        }
        else {
            helper(root->left, true, c + 1);
            helper(root->right, false, 1);
        }
    }
    
public:
    int longestZigZag(TreeNode* root) {
        helper(root->right, false, 1);
        helper(root->left, true, 1);
        return ans;
    }
};