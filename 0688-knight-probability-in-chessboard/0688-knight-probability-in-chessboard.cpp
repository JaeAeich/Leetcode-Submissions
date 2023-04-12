class Solution {
public:    
    double helper(vector<vector<vector<double>>> &dp, int n, int k, int i, int j){
        if(i>=n || j>=n || i<0 || j<0 ){
            return 0;
        } 
        if(k==0){
            return 1;
        }
        
        if(dp[k][i][j]!=-1) return dp[k][i][j]; 
        double ans = 0 ;
        vector<pair<int, int>> offset = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
        for(auto p:offset){
            ans+=helper(dp,n,k-1,i+p.first,j+p.second);
        }
        return dp[k][i][j]=(ans*1.0)/8;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(k+1, vector<vector<double>>(n, vector<double>(n, -1)));
        return helper(dp,n, k, row, column);
    }
};