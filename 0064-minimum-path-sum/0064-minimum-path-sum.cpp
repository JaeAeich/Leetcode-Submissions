class Solution {
public:
    int helper(vector<vector<int>>& v, vector<vector<int>>& dp, int n, int m, int i = 0, int j = 0) {
        //if out of bound return INTMAX as answer can't be here.
        if (i >= n || j >= m) {
            return INT_MAX;
        }
        //if reached bottom right return that value.
        if (i == n - 1 && j == m - 1) {
            return v[i][j];
        }
        //move down
        if (dp[i + 1][j] == -1) {
            dp[i + 1][j] = helper(v, dp, n, m, i + 1, j);
        }
        //move right
        if (dp[i][j + 1] == -1) {
            dp[i][j + 1] = helper(v, dp, n, m, i, j + 1);
        }
        
        return v[i][j] + min(dp[i][j + 1], dp[i + 1][j]);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return helper(grid, dp, n, m);
    }
};
