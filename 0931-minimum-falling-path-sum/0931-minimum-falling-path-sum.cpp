class Solution {
public:
    long min (long a, long b){
        return a>b?b:a;
    }
    
    long helperMemo(vector<vector<int>>& v, vector<vector<int>>& dp, int i=0, int j=0){
        //base case
        if(j<0 || j>=v[0].size()) return INT_MAX;
        if(i==v.size()-1) return v[i][j]; 
        //memoization
        if(dp[i][j]!=-1) return dp[i][j];
        //exploring all the possibility
        long bottom = helperMemo(v,dp,i+1,j);
        long bottom_left = helperMemo(v,dp,i+1,j-1);
        long bottom_right = helperMemo(v,dp,i+1,j+1);
        
        return dp[i][j]=v[i][j]+min(min(bottom, bottom_left), bottom_right);
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        int ans = INT_MAX;
        //calling for all the top layer
        for(int i=0;i<matrix.size();i++){
            ans = min(ans, helperMemo(matrix,dp,0,i));
        }
        return ans;
    }
};