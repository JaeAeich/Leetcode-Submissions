class Solution:
    def mostPoints(self, v: List[List[int]]) -> int:
        n = len(v)
        dp = {}
        def helper(v: List[List[int]], i = 0):
            if i >= len(v):
                return 0
            
            if i in dp:
                return dp[i]
            
            pick = v[i][0] + helper(v, i + 1 + v[i][1])
            leave = helper(v, i + 1)
            
            dp[i] = max(pick, leave)
            
            return dp[i]
        
        return helper(v);