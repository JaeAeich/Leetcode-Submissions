class Solution {
private:
    vector<vector<int>> finans;

    void helper(vector<int>& v, vector<bool>& vis, vector<int>& ans) {
        if (ans.size() == v.size()) {
            finans.push_back(ans);
            return;
        }
        for (int i = 0; i < v.size(); i++) {
            if (!vis[i]) {
                ans.push_back(v[i]);
                vis[i] = true;
                helper(v, vis, ans);
                vis[i] = false;
                ans.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n, false);
        vector<int> ans;
        helper(nums, vis, ans);
        return finans;
    }
};
