class Solution {
private:
    int helper(vector<int> &dp, int n){
        if(n <= 1) return 1;

        if(dp[n] != -1) return dp[n];
        
        int ans = 0;

        for(int i = 1; i <= n; i++){
            int left = i - 1;
            int right = n - i;

            ans += helper(dp, left) * helper(dp, right);
        }

        return dp[n] = ans;
    }
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, -1);
        return helper(dp, n);
    }
};