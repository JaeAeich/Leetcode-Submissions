class Solution {
public:
    int LCS(vector<vector<int>> &dp, string s, string t, int i=0, int j=0){
        if(i>=s.length() || j>=t.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take = INT_MIN;
        if(s[i]==t[j]){
            take = 1 + LCS(dp,s,t,i+1,j+1);
        }
        
        int leave1 = LCS(dp,s,t,i+1,j);
        int leave2 = LCS(dp,s,t,i,j+1);
        
        return dp[i][j] = max(max(take,leave1),leave2);
    }
    
    int LPS(vector<vector<int>> &dp,string s, int i, int j){
        if(i==j) return 1;
        if(i>j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int take = INT_MIN;
        
        if(s[i]==s[j]){
            return take = 2 + LPS(dp,s,i+1,j-1);
        }

        int leave1 = LPS(dp,s,i,j-1);
        int leave2 = LPS(dp,s,i+1,j);
        
        return dp[i][j] = max(leave1,leave2);
    }
    
    int LPSTab(string s){
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n));
        //dp[i][j] give the longest palindrom in s[i...j]
        for(int i=0;i<s.length();i++){
            dp[i][i]=1;
        }
        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                if(s[i]==s[j]){
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
                }
            }
        }
        return dp[0][n-1];
                                      
    }
    
    
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        // //method 1 : LCS of this string and rev of the string.
        // string temp = s;
        // reverse(begin(s),end(s));
        // int ans = LCS(dp,s,temp);
        
        // //method 2 : memoize
        // int ans = LPS(dp,s,0,n-1);
        
        //method 3 :Tab
        int ans =LPSTab(s);
        return ans == 0?1:ans;
    }
};