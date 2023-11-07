class Solution {
private:
    int ans = 0;
    int helper(vector<vector<int>> &dp, vector<vector<char>>& v, int i = 0, int j = 0){
        if(i >= v.size() || j >= v[0].size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int left =  helper(dp, v, i, j + 1);
        int down = helper(dp, v, i + 1, j);
        int diag = helper(dp, v, i + 1, j + 1);
        
        int ret = (v[i][j] == '0')? 0: 1 + min(left, min(down, diag));
        ans = max(ans, ret);
        return dp[i][j] = ret;
    }
public:
    int maximalSquare(vector<vector<char>>& v) {
        int n = v.size(), m = v[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        helper(dp, v);
        return ans * ans;
    }
};