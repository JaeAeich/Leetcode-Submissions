class Solution {
public:
    bool canJump(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n, 0);
        // I can reach the last idx from last idx
        dp[n-1] = 1;
        
        // Last idx from where I can reach the target 
        int last = n - 1;
        for(int i = n - 2; i >= 0; i--){
            // I can reach the last idx from here then I can reach goal
            if(i + v[i] >= last){
                dp[i] = 1;
                last = i;
            }
        }
        return dp[0];
    }
};