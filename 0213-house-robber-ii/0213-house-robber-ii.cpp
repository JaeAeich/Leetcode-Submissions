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
    
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        //if rob the first then leave the last house and vice versa.
        vector<int> dp(nums.size()+1,-1);
        int ans1=helper(nums,dp,0,nums.size()-1);
        dp=vector<int>(nums.size()+1,-1);
        int ans2=helper(nums,dp,1,nums.size());
        
        return max(ans1,ans2);
    }
};