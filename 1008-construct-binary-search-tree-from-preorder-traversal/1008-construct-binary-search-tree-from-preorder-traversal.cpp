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
    void push(TreeNode*& root, int val){
        if(!root){
            root = new TreeNode(val);
            return;
        }
        
        int curr_val = root->val;
        if(curr_val < val) push(root->right, val);
        else push(root->left, val);
    }
public:
    TreeNode* bstFromPreorder(vector<int>& v) {
        TreeNode* ans = nullptr;
        for(int i = 0; i < v.size(); i++){
            push(ans, v[i]);
        }
        return ans;
    }
};