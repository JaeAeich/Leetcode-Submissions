class Solution {
public:
    int helper(vector<vector<int>> &dp,string a, string b, int i=0, int j=0){
        //if a if finised then we have to add all the characters of a, and if b if finished then delete all the characters of a.
        if(j>=b.size()) return a.size()-i;
        if(i>=a.length()) return b.size()-j;
        //memoize
        if(dp[i][j]!=-1) return dp[i][j];
        //all possibility
        if(a[i]==b[j]){
            return dp[i][j] = helper(dp,a,b,i+1,j+1);
        }
        else{
            int del = 1 + helper(dp,a,b,i+1,j);
            int ins = 1 + helper(dp,a,b,i,j+1);
            int rep = 1 + helper(dp,a,b,i+1,j+1);
            //take min
            return dp[i][j]=min(min(del,ins),rep);
        }

    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size(),m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(dp,word1,word2);
    }
};