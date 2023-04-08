//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int helper(int v[], int size, int n, vector<int> &dp){
        if(size<0) return INT_MIN;
        if(size==0) return 0;
        
        
        if(dp[size]!=-1) return dp[size];
        
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,v[i]+helper(v,size-i-1,n,dp));
        }
        
        
        return dp[size]=ans;
    }
  
    int cutRod(int price[], int n) {
        //code here
        vector<int> dp(n+1,-1);
        return helper(price,n,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends