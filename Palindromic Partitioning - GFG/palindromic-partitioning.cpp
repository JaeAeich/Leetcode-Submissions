//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    bool check(string &s, int i, int j){
        while(i < j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    
    long long int helper(vector<vector<int>> &dp, string &s, int i = 0, int j = 0){
        if(j == s.size() - 1 || i == s.size() - 1){
            if(check(s, i, j)) return 0;
            return INT_MAX;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        long long int cut = INT_MAX;
        if(check(s, i, j)){
            cut = 1 + helper(dp, s, j + 1, j + 1);
        }
        long long int leave = helper(dp, s, i, j + 1);
        
        return dp[i][j] = min(cut, leave);
    }
public:
    int palindromicPartition(string str)
    {
        int n = str.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(dp, str);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends