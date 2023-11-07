class Solution {
private:
    vector<vector<int>> dp;
    
    int helper(string s, string t, int i = 0, int j = 0, int siz = 0){
        if(siz == t.size()) return 1;
        if(j >= t.size() || i >= s.size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ret = 0;
        if(s[i] == t[j]) ret = helper(s, t, i + 1, j + 1, siz + 1);
        ret += helper(s, t, i + 1, j, siz);
        
        return dp[i][j] = ret;
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        dp = vector<vector<int>>(n, vector<int>(m, -1));
        return helper(s, t);
    }
};