//{ Driver Code Starts
// Initial function Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int m=1e9+7;
    long helper(int n,vector<long> &dp){
        if( n<=1 ) return 0;
        if( n==2 ) return 1;
        if( dp[n]!=-1 ) return dp[n];
        return dp[n]=((n-1)*((helper(n-1,dp)%m)+(helper(n-2,dp)%m)))%m;
    }

    long int disarrange ( int N ) {
        vector<long> dp ( N+1, -1 );
        return helper ( N, dp );
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.disarrange(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends