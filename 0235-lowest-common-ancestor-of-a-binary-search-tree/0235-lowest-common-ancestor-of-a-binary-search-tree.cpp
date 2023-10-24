/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* r, TreeNode* p, TreeNode* q) {
        if(!r) return nullptr;
        if(r == p || r == q) return r;
        int rv = r->val;
        int pv = p->val;
        int qv = q->val;
        if((rv > pv && rv < qv) || (rv < pv && rv >qv)){
            return r;
        }
        else if(rv > pv && rv > qv) return lowestCommonAncestor(r->left, p, q);
        return lowestCommonAncestor(r->right, q, p);
    }
};