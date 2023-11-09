class Solution {
public:
    int longestArithSeqLength(vector<int>& v) {
        int n = v.size();
        if (n <= 1) return n;
        
        int maxi = *max_element(v.begin(), v.end());
        vector<vector<int>> dp(n, vector<int>(2 * maxi + 1, 1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = v[i] - v[j] + maxi;
                dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
            }
        }

        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < dp[i].size(); j++) {
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};
