class Solution {
public:
    //memoization
    int helper(vector<vector<int>>  &dp, string s1, string s2, int i, int j){
        //base case
        if(i<0 || j<0) return 0;
        
        //memoize
        if(dp[i][j]!=-1) return dp[i][j];
        
        //all possibilities
        int take = 0;
        if(s1[i]==s2[j]){
            take = 1 + helper(dp,s1,s2,i-1,j-1);
        }
        int move1 = helper(dp,s1,s2,i-1,j);
        int move2 = helper(dp,s1,s2,i,j-1);
        
        return dp[i][j]=max(max(take,move1),move2);
    }
    
    int helperTab(string s1, string s2){
        // int n = s1.length(),m=s2.length();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // dp[0][0] = 0;
        // dp[0][1] = 0;
        // dp[1][0] = 0;
        // for(int i=1;i<n;i++){
        //     for(int j=1;j<m;j++){
        //         int take = 0;
        //         if(s1[i]==s2[j]){
        //             take = 1 + dp[i-1][j-1];
        //         }
        //         int move1 = dp[i-1][j];
        //         int move2 = dp[i][j-1];
        //         dp[i][j]=max(max(take,move1),move2);
        //     }
        // }
        // return dp[n-1][m-1];
            int n = s1.length(),m=s2.length();
            vector<vector<int>> dp(n,vector<int>(m,-1));
            dp[0][0] = 0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    int take = 0;
                    if(s1[i]==s2[j]){
                        take = 1 + (i > 0 && j > 0 ? dp[i-1][j-1] : 0);
                    }
                    int move1 = (i > 0 ? dp[i-1][j] : 0);
                    int move2 = (j > 0 ? dp[i][j-1] : 0);
                    dp[i][j]=max(max(take,move1),move2);
                }
            }
            return dp[n-1][m-1];
        }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(),m=text2.length();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return helper(dp,text1,text2,n-1,m-1);
        return helperTab(text1,text2);
    }
};