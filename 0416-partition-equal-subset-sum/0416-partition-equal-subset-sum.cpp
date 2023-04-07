class Solution {
public:
    bool helper(vector<int> &v,vector<vector<int>> &dp,int t, int i=0, int sum=0){
        if(sum==t) return true;
        if(i>=v.size() || t<sum){
            return false;
        }
        if(dp[i][sum]==-1){
            bool ans1=helper(v,dp,t,i+1,sum+v[i]);
            if(ans1) {
                return dp[i][sum]=1;
            }
            bool ans2=helper(v,dp,t,i+1,sum);
            if(ans2) {
                return dp[i][sum]=1;
            }
        }
        return dp[i][sum]=0;
    }
    
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums),end(nums),0);
        vector<vector<int>> dp(nums.size()+1,vector<int>(21000,-1));
        if(sum%2!=0){
            return false;
        }
        return helper(nums,dp,sum/2);
    }
};