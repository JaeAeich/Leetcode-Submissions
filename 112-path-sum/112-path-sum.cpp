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
    bool dfs(TreeNode* root ,int t,int sum=0){
        //if nullptr is reached check return false.
        if(root==nullptr) return false;
        //if leaf node is reached check condition.
        if((sum+root->val)==t && !root->left && !root->right) return true;
        
        sum+=root->val;
        return dfs(root->right,t,sum)||dfs(root->left,t,sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return false;
        return dfs(root,targetSum);
    }
};