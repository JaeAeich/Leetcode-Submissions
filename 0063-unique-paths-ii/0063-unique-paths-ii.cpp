class Solution {
public:
    int helper(vector<vector<int>>& v,vector<vector<int>>& dp,int n,int m,int i=0, int j=0){
        //base case, note v[i][j] condition kept at last, so if any of prev conditions satisfy then we dont calculate out of bound values.
        if( i>=n || j>=m|| v[i][j]==1) return 0;
        if(i==n-1 && j==m-1) return 1;;
        //memoization
        if(dp[i][j]!=-1) return dp[i][j];
        //total ways
        int down = helper(v,dp,n,m,i+1,j);
        int right = helper(v,dp,n,m,i,j+1);
        
        return dp[i][j]=right+down;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(),m=obstacleGrid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return helper(obstacleGrid,dp,n,m);
    }
};