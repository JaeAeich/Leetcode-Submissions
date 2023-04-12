class Solution {
public:
    int helper(vector<int>& v,vector<vector<int>> &dp, bool buy=false, int i=0){
        //base case
        if(i>=v.size()) return 0;
        if(!buy && i==v.size()-1) return 0; 
        
        //memoize
        if(dp[buy][i]!=-1) return dp[buy][i];
        
        //trade
        int trade=0;
        if(!buy){
            trade = -v[i]+helper(v,dp,!buy,i+1);
        }
        else {
            trade = +v[i] + helper(v,dp,!buy,i+2);
        }
        
        //cooldown
        int hold = helper(v,dp,buy,i+1);
        //return
        return dp[buy][i]=max(trade,hold);
    }
    
    int maxProfit(vector<int>& prices) {
        //initialise dp vector
        vector<vector<int>> dp(2,vector<int>(prices.size(),-1));
        return helper(prices,dp);
    }
};