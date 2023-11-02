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
    vector<int> rightSideView(TreeNode* root) {
        stack<pair<TreeNode*,int>> s;
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});
        s.push({root, 0});
        vector<int> ans;
        if(!root) return ans;
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(node && node->left){
                q.push({node->left, level + 1});
                s.push({node->left, level + 1});
            }
            if(node && node->right){
                q.push({node->right, level + 1});
                s.push({node->right, level + 1});
            }
        }
        int prev = INT_MAX;
        while(!s.empty()){
            TreeNode* node = s.top().first;
            int level = s.top().second;
            s.pop();
            
            if(level < prev){
                ans.push_back(node->val);
                prev = level;
            }
        }
        reverse(begin(ans), end(ans));
        
        return ans;
    }
};