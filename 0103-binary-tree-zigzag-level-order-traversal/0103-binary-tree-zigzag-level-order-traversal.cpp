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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*,int>> q;
        if(!root) return ans;
        map<int,vector<int>> m;
        q.push({root,0});
        while(!q.empty()){
            auto node = q.front().first;
            int level = q.front().second;
            q.pop();
            m[level].push_back(node->val);
            if(node->left) q.push({node->left, level + 1});
            if(node->right) q.push({node->right, level + 1});
        }
        bool rev = false;
        for(auto it = begin(m); it != end(m); it++){
            auto temp = it->second;
            if(rev){
                reverse(begin(temp),end(temp));
            }
            rev =!rev;
            ans.push_back(temp);
        }
        return ans;
    }
};