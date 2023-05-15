//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long countBits(long long N) {
        long long count = 0;
        for (int i = 0; i < 32; i++) {
            long long x = 1LL << i;
            if (x > N) {
                break;
            }
            count += (N + 1) / (x * 2) * x;
            if ((N + 1) % (x * 2) > x) {
                count += (N + 1) % (x * 2) - x;
            }
        }
        return count;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends