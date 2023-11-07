class Solution {
public:
    int maxNonDecreasingLength(vector<int>& v, vector<int>& a) {
        int ans = 1;
        int n = v.size();
        vector<vector<int>> dp(n, vector<int>(2, 1));

        for (int i = 1; i < n; i++) {
                if (v[i - 1] <= v[i]) {
                    dp[i][0] = max(dp[i][0], dp[i - 1][0] + 1);
                }
                if (a[i - 1] <= v[i]) {
                    dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);
                }
                if (a[i - 1] <= a[i]) {
                    dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1);
                }
                if (v[i-1] <= a[i]) {
                    dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1);
                }
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
        
        return ans;
    }
};
