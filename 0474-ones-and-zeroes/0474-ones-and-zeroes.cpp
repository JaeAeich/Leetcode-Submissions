class Solution {
private:
    vector<vector<vector<int>>> dp;

    int helper(vector<string>& v, int m, int n, int i = 0) {
        if (i == v.size()) return 0;

        if (dp[m][n][i] != -1) return dp[m][n][i];

        int zero = 0;
        for (int k = 0; k < v[i].size(); k++) zero += (v[i][k] == '0' ? 1 : 0);
        int one = v[i].size() - zero;

        int pick = 0;
        if(m - zero >= 0 && n - one >= 0) pick = 1 + helper(v, m - zero, n - one, i + 1);
        int leave = helper(v, m, n, i + 1);

        return dp[m][n][i] = max(pick, leave);
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        dp = vector<vector<vector<int>>>(m + 1, vector<vector<int>>(n + 1, vector<int>(size, -1)));
        return helper(strs, m, n);
    }
};
