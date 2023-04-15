class Solution {
public:
    int helper(vector<int>& v, vector<vector<int>> &dp,bool buy=false,int i=0){
        if(i>=v.size()) return 0;
        if(dp[buy][i]!=-1) return dp[buy][i];
        int trade = INT_MIN;
        if(!buy){
            if(i<v.size()-1) trade = -v[i] + helper(v,dp,!buy,i+1);
        }
        else{
            trade = +v[i] + helper(v,dp,!buy,i+1);
        }
        
        int hold = helper(v,dp,buy,i+1);
        
        return dp[buy][i]=max(trade,hold);
    }
   
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(2,vector<int>(n+1,-1));
       return helper(prices,dp); 
    }
};