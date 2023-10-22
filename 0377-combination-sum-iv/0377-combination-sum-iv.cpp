class Solution {
private:
    int helper(vector<int> &dp, vector<int> &v, int t){
        if(t < 0) return 0;
        if(t == 0) return 1;
        
        int ret = 0;
        
        if(dp[t] != -1) return dp[t];
        
        for(int i = 0; i < v.size(); i++)
        {
            ret += helper(dp, v, t - v[i]);
        }
        
        return dp[t] = ret;
    }
public:
    int combinationSum4(vector<int>& v, int t) {
        vector<int> dp(t + 1, - 1);
        return helper(dp, v, t);
    }
};