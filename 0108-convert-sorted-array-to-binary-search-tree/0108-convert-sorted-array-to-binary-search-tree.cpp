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
    TreeNode* helper(vector<int> &v, int i, int j){
        if(i > j) return nullptr;
        int mid = (i + j) / 2;
        TreeNode* ans = new TreeNode(v[mid]);
        ans->left = helper(v, i, mid - 1);
        ans->right = helper(v, mid + 1, j);
        return ans;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& v) {
        return helper(v, 0, v.size() - 1);
    }
};