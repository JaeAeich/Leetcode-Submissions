class Solution {
public:
    bool helper(vector<int>& nums,vector<vector<int>> &dp,int t, int i){
        //base case
        if(t==0) return true;
        if(t<0 | i<0) return false;
        
        //memoize
        if(dp[t][i]!=-1) return dp[t][i];
        
        return dp[t][i]=helper(nums,dp,t-nums[i],i-1) | helper(nums,dp,t,i-1);
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(begin(nums),end(nums),0);
        //can't be divided into 2 parts.
        if(sum%2!=0) return false;
        
        vector<vector<int>> dp(sum/2+1,vector<int>(n,-1));
        return helper(nums,dp,sum/2,n-1);
    }
};