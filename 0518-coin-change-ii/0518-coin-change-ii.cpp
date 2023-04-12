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
    
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(amount+1,vector<int>(n,-1));
        return helper(coins,dp,amount,n-1);
    }
};