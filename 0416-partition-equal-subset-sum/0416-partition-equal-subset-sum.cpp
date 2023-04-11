class Solution {
public:
    bool helper(vector<int> &v,vector<vector<int>> &dp,int sum, int tot=0, int i=0){
        if(i>=v.size() || tot>sum) return 0;
        if(sum==tot) return 1;
        
        if(dp[tot][i]!=-1) return dp[tot][i];
        
        return dp[tot][i]=helper(v,dp,sum,tot+v[i],i+1) || helper(v,dp,sum,tot,i+1);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate ( begin(nums),end(nums),0);
        if(sum%2!=0) return 0;
        
        int maxx = *max_element(begin(nums),end(nums));
        vector<vector<int>> dp(sum/2+maxx+1,vector<int>(nums.size(),-1));
        
        return helper(nums,dp,sum/2);
    }
};