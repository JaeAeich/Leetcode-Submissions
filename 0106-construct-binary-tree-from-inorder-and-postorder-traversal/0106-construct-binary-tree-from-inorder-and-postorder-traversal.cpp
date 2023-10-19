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
    TreeNode* helper(vector<int>& inorder, int ii, int ij, vector<int>& postorder, int pi, int pj, map<int,int> &m)
    {
        if(ii > ij || pi > pj) return NULL;
        TreeNode* root = new TreeNode(postorder[pj]);
        int idx = m[postorder[pj]];
        int offset = idx - ii;
        
        root->left = helper(inorder, ii, idx - 1, postorder, pi, pi + offset - 1, m);
        root->right = helper(inorder, idx + 1, ij, postorder, pi + offset , pj - 1, m);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        map<int,int> m;
        for(int i = 0; i < inorder.size(); i++){
            m[inorder[i]] = i;
        }
        return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size()-1, m);
    }
};