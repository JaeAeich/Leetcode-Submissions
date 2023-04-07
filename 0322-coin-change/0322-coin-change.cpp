class Solution {
public:
    // //recursion
    // long helper(vector<int>& v, long t, long i=0){
    //     //if t becomes 0 it means that, this is a possibility. 
    //     if(t==0){
    //         return 0;
    //     }
    //     //not a possiblity
    //     if(t<0 || i>=v.size()){
    //         return INT_MAX;
    //     }
    //     //All the possible ways to make that target
    //     long takeAndStay = 1 + helper (v,t-v[i],i);
    //     long takeAndMove = 1 + helper (v,t-v[i],i+1);
    //     long move = helper (v,t,i+1);
    //     //return minimum of all the values
    //     int ans = min(min(takeAndStay , takeAndMove) , move);
    //     return ans ;
    // }
    
    //dp
    long helper(vector<int>& v,vector<vector<int>>& dp, long t, long i=0){
        //if t becomes 0 it means that, this is a possibility. 
        if(t==0){
            return 0;
        }
        //not a possiblity
        if(t<0 || i>=v.size()){
            return INT_MAX;
        }
        
        //if stored no need to calculate.
        if(dp[t][i]!=-1) return dp[t][i];
        
        //All the possible ways to make that target
        long takeAndStay = 1 + helper (v,dp,t-v[i],i);
        long takeAndMove = 1 + helper (v,dp,t-v[i],i+1);
        long move = helper (v,dp,t,i+1);
        
        //return minimum of all the values
        int ans = min(min(takeAndStay , takeAndMove) , move);
        return dp[t][i]=ans ;
    }
    /*
    Constraints:

        1 <= coins.length <= 12
        1 <= coins[i] <= 2^31 - 1
        0 <= amount <= 104

    */
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(1e4+1,vector<int>(12,-1));
        long ans = helper(coins,dp,amount);
        return ans>=INT_MAX?-1:ans ;
    }
};