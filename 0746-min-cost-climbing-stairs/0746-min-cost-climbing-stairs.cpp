class Solution {
public:
    int helperMemo(vector<int>& v,vector<int>& dp,int i=0){
        if(i>=v.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=min(v[i]+helperMemo(v,dp,i+1),v[i]+helperMemo(v,dp,i+2));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        if(cost.size()==1) return cost[0];
        return min(helperMemo(cost,dp),helperMemo(cost,dp,1));
    }
};