class Solution {
private:
    int helper(vector<vector<int>> &dp, string &s, int i, int j){
        if(i > j) return 0;
        int ans;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == s[j]){
            ans = helper(dp, s, i + 1, j - 1);
        }
        else{
            ans = 1 + min(helper(dp, s, i, j - 1), helper(dp, s, i + 1, j));
        }
        
        return dp[i][j] = ans;
    }
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(dp, s, 0, n - 1);
    }
};