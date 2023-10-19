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
    TreeNode* helper(vector<int> &v, int i, int j){
        if(i > j) return nullptr;
        int lo = i, hi = j;
        int mid = (i + j)/2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = helper(v, i, mid - 1);
        root->right = helper(v, mid + 1, j);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& v) {
        int n = v.size();
        return helper(v, 0, n - 1);
    }
};