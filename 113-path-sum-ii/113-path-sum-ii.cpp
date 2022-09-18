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
    vector<vector<int>> finans={};
    
    void dfs(TreeNode* root, int t, vector<int> ans={},int sum=0){
        //if nullptr reached that means condition hasn't been satisfied.
        if(!root) return;
        //condition is satisfied, check if its leaf node.
        if(!root->left && !root->right){
            if(sum+root->val==t){
                ans.push_back(root->val);
                finans.push_back(ans);
            }
            return;
        }
        ans.push_back(root->val);
        dfs(root->left,t,ans,sum+root->val);
        dfs(root->right,t,ans,sum+root->val);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum);
        return finans;
    }
};