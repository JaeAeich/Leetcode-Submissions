class Solution {
public:
    int helper(vector<int>& v,vector<vector<int>> &dp,int t,int norm,int i){
        if(i<0 && t==0) return 1;
        if(i<0) return 0;
        
        if(dp[t+norm][i]!=-1) return dp[t+norm][i];
        
        int add = helper(v,dp,t-v[i],norm,i-1);
        int subs = helper(v,dp,t+v[i],norm,i-1);
        
        return dp[t+norm][i]=add + subs;
    }
    //-2000 ==>-t-sum
    //normalized it by +2000 => -t-sum + t + sum
    //2000
    //after normalizing we are at 4000 ==> 2*(t+sum);
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(begin(nums),end(nums),0);
        vector<vector<int>> dp(2*(abs(target)+sum+2),vector<int>(nums.size()+1,-1));
        int norm = abs(target)+sum;
        return helper(nums,dp,target,norm,nums.size()-1);
    }
};