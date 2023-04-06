class Solution {
public:
    int helper(vector<int> &v,vector<int> &dp, int i, int j){
        if(i>j-1){
            return 0;
        }
        if(dp[i]==-1){
            //if rob this house then move to next to next house to rob else dont rob this house.
            dp[i]=max(v[i]+helper(v,dp,i+2,j),helper(v,dp,i+1,j));
        }
        return dp[i];
    }
    
    int rob(vector<int>& v) {
        int i=0, j=v.size();
        vector<int> dp(j+1,-1);
        return (helper(v,dp,i,j));
    }
};