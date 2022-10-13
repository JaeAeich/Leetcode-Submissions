//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	void immediateSmaller(vector<int>&v, int n) {
	    //  code here
	   // stack<int> s;
	   // for(int i=0;i<n;i++){
	   //     while(!s.empty() && v[i]<v[s.top()]){
	   //         v[s.top()]=v[i];
	   //         s.pop();
	   //     }
	   //     s.push(i);
	   // }
	   // while(!s.empty()){
	   //     v[s.top()]=-1;
	   //     s.pop();
	   // }
	   for(int i=0;i<n-1;i++){
	       if(v[i]>v[i+1]){
	           v[i]=v[i+1];
	       }
	       else{
	           v[i]=-1;
	       }
	   }
	   v[n-1]=-1;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.immediateSmaller(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends