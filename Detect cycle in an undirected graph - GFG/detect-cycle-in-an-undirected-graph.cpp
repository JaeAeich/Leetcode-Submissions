//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool helper(int node, bool vis[], vector<int> adj[]) {
        queue<pair<int, int>> q;
        q.push({node, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto child : adj[node]) {
                if (child != parent) {
                    if (vis[child]) return true;
                    vis[child] = true; // Mark the child as visited
                    q.push({child, node});
                }
            }
        }

        return false;
    }

public:
    // Function to detect a cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        bool vis[V];
        for (int i = 0; i < V; i++) {
            vis[i] = false; // Initialize the vis array
        }

        for (int i = 0; i < V; i++) {
            if (!vis[i] && helper(i, vis, adj)) return true;
        }

        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends