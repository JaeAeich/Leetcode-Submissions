class Solution {
public:
    int findLongestChain(vector<vector<int>>& v) {
        int n = v.size();
        vector<int> dp(n, 1);
        sort(begin(v), end(v));
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                int s = v[i][0];
                int e = v[j][1];
                if(s > e) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                } else dp[i] = max(dp[i], dp[j]);
            }
        }
        
        return dp[n - 1];
    }
};
