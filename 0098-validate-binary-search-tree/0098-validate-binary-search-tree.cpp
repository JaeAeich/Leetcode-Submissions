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
    bool check(TreeNode* root, int val, bool flag){
        if(!root) return true;
        int curr = root->val;
        
        if(!flag){
            return curr < val && check(root->right, val, flag) && check(root->left, val, flag); 
        }
        else{
            return curr > val && check(root->right, val, flag) && check(root->left, val, flag); 
        }
    }
    
    bool dfs(TreeNode* root){
        if(!root) return true;
        int val = root->val;
        bool left = check(root->left, val, false);
        bool right = check(root->right, val, true);
        
        return left && right && dfs(root->left) && dfs(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root);
    }
};