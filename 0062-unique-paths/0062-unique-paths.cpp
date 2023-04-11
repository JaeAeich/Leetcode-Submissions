class Solution {
public:
    int helperMemo(vector<vector<int>> &dp, int n, int m,int i=0, int j=0){
        if(j>=m || i>=n) return 0;
        if(i==n-1 && j==m-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int down = helperMemo(dp,n,m,i+1,j);
        int right = helperMemo(dp,n,m,i,j+1);
        
        return dp[i][j] = down + right;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,(vector<int> (n+1,-1)));
        return helperMemo(dp,m,n);
    }
};