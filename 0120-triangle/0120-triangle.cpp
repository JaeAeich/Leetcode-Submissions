class Solution {
public:
    // //recursive
    // int helper(vector<vector<int>> &v,int n,int i=0,int j=0){
    //     if(i>=n || j>=v[i].size()){
    //         return INT_MAX;
    //     }
    //     if(i==n-1){
    //         return v[i][j]; 
    //     }
    //     int downRight=helper(v,n,i+1,j);
    //     int downLeft=helper(v,n,i+1,j+1);
    //     return v[i][j]+min(downRight,downLeft);
    // }
    //dp
    int helper(vector<vector<int>> &v,vector<vector<int>> &dp,int n,int i=0,int j=0){
        if(i>=n || j>=v[i].size()){
            return INT_MAX;
        }
        if(i==n-1){
            return v[i][j]; 
        }
        if(dp[i+1][j]==-1){
            dp[i+1][j]=helper(v,dp,n,i+1,j);
        }
        if(dp[i+1][j+1]==-1){
            dp[i+1][j+1]=helper(v,dp,n,i+1,j+1);
        }
        return v[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return helper(triangle,dp,n);
    }
};