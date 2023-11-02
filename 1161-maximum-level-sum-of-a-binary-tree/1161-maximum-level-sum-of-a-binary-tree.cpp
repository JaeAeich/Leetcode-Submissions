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
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        int level = 1;
        q.push({root, level});
        int prev = -1;
        unordered_map<int,int> m;
        if(!root) return 0;
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            m[level] += node->val;
            if(node->right) q.push({node->right, level + 1});
            if(node->left) q.push({node->left, level + 1});

        }
        int ans = INT_MAX;
        int s = INT_MIN;
        for(auto it = begin(m); it != end(m); it++){
            int sum = it->second;
            int level = it->first;
            if(sum > s) {
                ans = level; 
                s = sum;
            }
            if(sum == s){
                ans = min(ans, level);
            }
        }
        return ans;
    }
};