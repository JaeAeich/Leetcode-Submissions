class Solution {
public:
    int helperMemo(vector<int> &v,vector<vector<int>> &dp, int prevIdx=-1, int i=0){
        if(i>=v.size()) return 0;
        //prevIdx+1 'cuz prevIdx is -1.
        if(dp[prevIdx+1][i]!=-1) return dp[prevIdx+1][i];
        //all possibility
        int take = INT_MIN;
        if(prevIdx==-1 || v[i]>v[prevIdx]){
            take = 1 + helperMemo(v,dp,i,i+1);
        }
        int leave = helperMemo(v,dp,prevIdx,i+1);
        
        return dp[prevIdx+1][i]=max(take,leave);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n,-1));
        return helperMemo(nums,dp);
    }
};