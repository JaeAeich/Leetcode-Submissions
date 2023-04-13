class Solution {
public:
    int helper(vector<int> &v,vector<vector<int>>&dp, int t,int i){
        if(t==0) return 1;
        if(t<0 || i<0) return 0;
        if(dp[t][i]!=-1) return dp[t][i];
        int take = helper(v,dp,t-v[i],i);
        int move = helper(v,dp,t,i-1);
        
        return dp[t][i]=take + move;
    }
    
   int helperTab(vector<int> &v, int t) {
    int n = v.size();
    vector<vector<int>> dp(t+1, vector<int>(n+1));
    
    // Base case
    for (int i = 0; i <= n; i++) {
        dp[0][i] = 1;
    }
    
    // Fill the table in bottom-up manner
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= n; j++) {
            int take = (i >= v[j-1]) ? dp[i - v[j-1]][j] : 0;
            int move = dp[i][j-1];
            dp[i][j] = take + move;
        }
    }
    
    // Return the result
    return dp[t][n];
}
    
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        // vector<vector<int>> dp(amount+1,vector<int>(n,-1));
        // return helper(coins,dp,amount,n-1);
        return helperTab(coins,amount);
    }
};