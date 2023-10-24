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
    TreeNode* helper(vector<int>& v, vector<int>& a, map<int, int>& m, int pi, int pj, int ii, int ij){
        if(pi > pj || ii > ij) return nullptr;
        
        int ri = m[v[pi]];
        int offset = ri - ii;
        
        TreeNode* ans = new TreeNode(v[pi]);
        ans->left = helper(v, a, m, pi + 1, pi + offset, ii, ri - 1);
        ans->right = helper(v, a, m, pi + offset + 1, pj, ri + 1, ij);
        return ans;
    }
public:
    TreeNode* buildTree(vector<int>& v, vector<int>& a) {
        int n = v.size();
        map<int, int> m;
        for(int i = 0; i < n; i++){
            m[a[i]] = i;
        }
        return helper(v, a, m ,0, n - 1, 0, n - 1);
    }
};