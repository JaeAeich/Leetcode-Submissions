//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
private:
    vector<string> finans;

    void helper(vector<vector<int>>& v, vector<vector<bool>> &vis, string ans = "", int i = 0, int j = 0) {
        if (i >= v.size() || j >= v[0].size() || v[i][j] == 0 || vis[i][j])
            return;
        if (i == v.size() - 1 && j == v[0].size() - 1) {
            finans.push_back(ans);
            return;
        }
        
        vis[i][j] = true;
        
        ans += "R";
        helper(v, vis, ans, i, j + 1);
        ans.pop_back();
        
        ans += "L";
        helper(v, vis, ans, i , j - 1);
        ans.pop_back();
        
        ans += "D";
        helper(v, vis, ans, i + 1, j);
        ans.pop_back();
        
        ans += "U";
        helper(v, vis, ans, i - 1, j);
        ans.pop_back();
        
        vis[i][j] = false;
    }
    

public:
    vector<string> findPath(vector<vector<int>>& v, int n) {
        int m = v[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        helper(v, vis);
        return finans;
    }
};


    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends