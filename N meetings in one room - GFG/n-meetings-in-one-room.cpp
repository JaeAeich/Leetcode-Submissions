//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int s[], int e[], int n)
    {
        // Your code here
        int ans = 0;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({s[i],e[i]});
        }
        sort(begin(v),end(v),[](pair<int,int>&a, pair<int,int> &b){return a.second<b.second;});
        int prevE = INT_MIN;
        for(auto p: v){
            if(p.first>prevE) {
                ans ++;
                prevE=p.second;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends