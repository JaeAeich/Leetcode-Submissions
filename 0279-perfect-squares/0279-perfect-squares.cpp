class Solution {
public:
//     //recursion
//     long helper(vector<int> &v, int t, int i=1){
//         if(t==0) return 0;
//         if(t<0 || i>=v.size()) return INT_MAX;
        
//         long takeAndStay = 1 + helper(v,t-v[i],i);
//         long takeAndMove = 1 + helper(v,t-v[i],i+1);
//         long move = helper(v,t,i+1);
        
//         long ans = min(min(takeAndStay,takeAndMove),move);
        
//         return ans;
//     }
    
    //dp
    int min(int a, int b){
        return a>b?b:a;
    }
    
    long helper(vector<int> &dp, int t){
        if(t==0) return 0;
        if(t<0 ) return INT_MAX;
        if(dp[t]!=-1) return dp[t];
        int ans=INT_MAX;
        for(int i=1;i*i<=t;i++){
            ans=min(ans,1+helper(dp,t-i*i));
        }
        return dp[t]=ans;
    }
    
    int numSquares(int n){
        vector<int> dp(n+1,-1);
        int ans=helper(dp,n);
        return ans;
    }
};