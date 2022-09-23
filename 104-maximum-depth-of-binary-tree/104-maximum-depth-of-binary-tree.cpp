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
    //recursive
    int maxDepth(TreeNode* root,int c=0) {
        if(!root) return c;
        c++;
        int l=maxDepth(root->left,c);
        int r=maxDepth(root->right,c);
        return max(l,r);
    }
    
    
};