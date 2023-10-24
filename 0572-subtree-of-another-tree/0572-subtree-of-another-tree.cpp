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
    bool isSame(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if((!p && q) || (p && !q)) return false;
        
        return p->val == q->val && isSame(p->right, q->right) && isSame(p->left, q->left);
    }
public:
    bool isSubtree(TreeNode* r, TreeNode* s) {
        // Base case
        if(!r && !s) return true;
        if((!r && s) || (!s && r)) return false;
        
        // Are root and subtree same?
        if(isSame(r, s)) return true;
        
        // Are root->left and subtree same?
        bool left = isSubtree(r->left, s);
        
        // Are root->right and subtree same?
        bool right = isSubtree(r->right, s);
        
        return left || right;
    }
};