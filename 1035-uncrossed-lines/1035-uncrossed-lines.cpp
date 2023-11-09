class Solution {
public:
    int maxUncrossedLines(vector<int>& v, vector<int>& a) {
        int n = v.size(), m = a.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                int ans = 0;
                if(v[i] == a[j]){
                    ans = 1 + dp[i + 1][j + 1];
                }
                else {
                    ans = max(dp[i][j + 1], dp[i +1][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
};